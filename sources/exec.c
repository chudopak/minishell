#include "../headers/overall.h"

void launch_exec(char **args)
{
	pid_t	pid;
	pid_t	wpid;

	pid = fork();
	if (pid == 0)
	{
		// child process
		if (execve())
	}
}

void distribution_to_exec(t_all *all, t_command *command)
{
	if (!ft_strcmp(command->cmd[0], "echo"))
		ft_echo(&command->cmd[1]);
	if (!ft_strcmp(command->cmd[0], "cd"))
		ft_cd(all, command->cmd[1]);
	if (!ft_strcmp(command->cmd[0], "env"))
		ft_env(all);
	if (!ft_strcmp(command->cmd[0], "pwd"))
		ft_pwd();
	if (!ft_strcmp(command->cmd[0], "exit"))
		ft_exit(&command->cmd[1]);
	if (!ft_strcmp(command->cmd[0], "unset"))
		ft_unset(all, &command->cmd[1]);
	if (!ft_strcmp(command->cmd[0], "export"))
		ft_export(&command->cmd[1], all);
	else
		launch_exec(command->cmd);
}