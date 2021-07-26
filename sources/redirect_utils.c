#include "../headers/overall.h"

void	open_redirect(t_all *all, t_command *command)
{
	(void )all;
	if (command->redirectout != -1)
	{
		close(STDOUT_FILENO);
		dup2(command->redirectout, STDOUT_FILENO);
	}
	if (command->redirectin != -1)
	{
		close(STDIN_FILENO);
		dup2(command->redirectin, STDIN_FILENO);
	}
}

void	close_redirect(t_all *all, t_command *command)
{
	if (command->redirectin != -1 || command->redirectout != -1)
	{
		if (command->pipeout)
			return ;
		else
		{
			dup2(all->stdin_tmp, STDIN_FILENO);
			dup2(all->stdout_tmp, STDOUT_FILENO);
		}
	}
}