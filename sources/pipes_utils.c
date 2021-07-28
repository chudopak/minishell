#include "../headers/overall.h"

void	open_pipes(t_all *all, t_command *command)
{
	if (command->pipeout)
	{
		if (pipe(all->fd) == -1)
		{
			g_errno = errno;
			ft_putstr_fd("Pipe, failed, initializing undefined behavior\n", 2);
		}
	}
}

void	check_left_pipe(t_all *all, t_command *command)
{
	if (command->pipeout)
	{
		dup2(all->fd[0], STDIN_FILENO);
		close(all->fd[0]);
		dup2(all->stdout_tmp, STDOUT_FILENO);
	}
	if (!command->pipeout)
		dup2(all->stdin_tmp, STDIN_FILENO);
}

void	check_right_pipe(t_all *all, t_command *command)
{
	if (command->pipeout)
	{
		open_pipes(all, command);
		dup2(all->fd[1], STDOUT_FILENO);
		close(all->fd[1]);
	}
}
