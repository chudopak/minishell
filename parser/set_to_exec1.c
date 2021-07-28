#include "../headers/overall.h"

void	clear_leftover(t_command *command, t_lst **args)
{
	free_cmd(command->cmd);
	if (command->path)
		free(command->path);
	lstclear_char(args);
	args = NULL;
	if (command->redirectin != -1)
		close(command->redirectin);
	if (command->redirectout != -1)
		close(command->redirectout);
}

int	check_last_arg_for_null(t_lst *last_arg)
{
	if (!last_arg->str)
		return (put_endline(&last_arg));
	return (ALL_OK);
}

void	set_token_pipes(t_all *all, t_command *command, char symbol)
{
	if (symbol == '|')
	{
		if (all->pipein)
			command->pipein = all->pipein;
		else
		{
			all->pipein = 1;
			command->pipein = 0;
		}
		command->pipeout = 1;
	}
	else
	{
		if (all->pipein)
		{
			command->pipein = 1;
			all->pipein = 0;
		}
		else
			command->pipein = 0;
		command->pipeout = 0;
	}
}

t_command	set_token(t_all *all, char symbol)
{
	t_command	command;

	command.cmd = NULL;
	set_token_pipes(all, &command, symbol);
	command.redirectin = -1;
	command.redirectout = -1;
	command.path = NULL;
	return (command);
}
