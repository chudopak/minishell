#include "../headers/overall.h"

static void	set_token_semicolon(t_all *all, t_command *command)
{
	if (all->pipein)
	{
		command->pipein = 1;
		all->pipein = 0;
	}
	else
		command->pipein = 0;
	command->pipeout = 0;
	command->redirectin = all->redirectin;
	command->redirectout = all->redirectout;
}

static t_command	set_token(t_all *all, char symbol)
{
	t_command	command;

	command.cmd == NULL;
	if (symbol == '|')
	{
		if (all->pipein)
			command.pipein = all->pipein;
		else
		{
			all->pipein = 1;
			command.pipein = 0;
		}
		command.redirectin = all->redirectin;
		command.redirectout = all->redirectout;
		command.pipeout = 1;
	}
	else
		set_token_semicolon(all, &command);
	return (command);
}

static	char	**convert_to_array(t_lst *args)
{
	int		size;
	int		i;
	char	**arguments;

	size = ft_lstsize(args);
	arguments = malloc(sizeof(char *) * (size + 1));
	arguments[size] = NULL;
	i = -1;
	while (++i < size)
	{
		arguments[i] = ft_strdup(args->str);
		args = args->next;
	}
	return (arguments);
}

static void	set_new_lst(t_lst **args, t_lst **last_arg, char **data)
{
	*args = lstnew_char(NULL);
	*last_arg = *args;
	while (*(*data + 1) == ' ')
		++*data;
}

void	set_to_exec(t_all *all, t_lst **args, t_lst **last_arg, char **data)
{
	t_command	command;

	command = set_token(all, **data);
	command.cmd = convert_to_array(*args);
	/*
	**ALMAZ, mesto dlya tvoei function
	*/
	free_cmd(command.cmd);
	lstclear_char(*args);
	set_new_lst(args, last_arg, data);
}