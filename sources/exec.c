#include "../headers/overall.h"

void launch_exec(t_all *all, char **args, t_command *command)
{
	pid_t	pid;
	char *correct_path;

	correct_path = split_path(all, command);
	if (!correct_path)
	{
		ft_putstr_fd(*command->cmd, STDOUT_FILENO);
		puterror2("command not found", ": ", STDOUT_FILENO);
		return ;
	}
//	all->envp_copy = env_to_charpp(all);
	pid = fork();
	if (pid == 0)
	{
		// child process
		if (execve(correct_path, args, all->envp_copy) == -1)
		{
			ft_putstr_fd(*command->cmd, STDOUT_FILENO);
			puterror2("command not found", ": ", STDOUT_FILENO);
			g_errno = errno;
			return ;
		}
		exit(g_errno);
	}
	else if (pid < 0)
		// fail
		puterror("fork failed", 1);
	else
		// parent process
	{
		wait(&pid);
		free(correct_path);
	}
}

static int find_built_in_func2(t_all *all, t_command *command)
{
	if (!ft_strcmp(command->cmd[0], "exit"))
	{
		ft_exit(&command->cmd[1]);
		return (1);
	}
	else if (!ft_strcmp(command->cmd[0], "unset"))
	{
		ft_unset(all, &command->cmd[1]);
		return (1);
	}
	else if (!ft_strcmp(command->cmd[0], "export"))
	{
		ft_export(&command->cmd[1], all);
		return (1);
	}
	return (0);
}
static int find_built_in_func(t_all *all, t_command *command)
{
	if (!ft_strcmp(command->cmd[0], "echo"))
	{
		ft_echo(&command->cmd[0]);
		return (1);
	}
	else if (!ft_strcmp(command->cmd[0], "cd"))
	{
		ft_cd(all, command->cmd[1]);
		return (1);
	}
	else if (!ft_strcmp(command->cmd[0], "env"))
	{
		ft_env(all);
		return (1);
	}
	else if (!ft_strcmp(command->cmd[0], "pwd"))
	{
		ft_pwd();
		return (1);
	}
	return (find_built_in_func2(all, command));
}

void distribution_to_exec(t_all *all, t_command *command)
{
	check_right_pipe(all, command);
	open_redirect(all, command);
	if (!command->cmd[0])
		return ;
	if (!find_built_in_func(all, command))
		launch_exec(all, command->cmd, command);
	close_redirect(all, command);
	check_left_pipe(all, command);
	free_command(command, all);
}