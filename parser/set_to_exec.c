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

	command.cmd = NULL;
	if (symbol == '|')
	{
		if (all->pipein)
			command.pipein = all->pipein;
		else
		{
			all->pipein = 1;
			command.pipein = 0;
		}
		command.redirectin = all->redirectin;				//fix that
		command.redirectout = all->redirectout;				//fix that
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

	size = lst_size(args);
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

static int	set_new_lst(t_all *all, t_lst **args, t_lst **last_arg, char **data)
{
	(*data)++;
	*args = lstnew_char(NULL);
	if (!*args)
		return (BAD_MALLOC);
	*last_arg = *args;
	while (**data == ' ')
		++*data;
	all->redirect = 0;
	all->redirectin = -1;
	all->redirectout = -1;
	return (ALL_OK);
}

static int	check_last_arg_for_null(t_lst *last_arg)
{
	if (!last_arg->str)
		return (put_endline(&last_arg));
	return (ALL_OK);
}

void	set_to_exec(t_all *all, t_lst **args, t_lst **last_arg, char **data)
{
	t_command	command;

	command = set_token(all, **data);
	if (check_last_arg_for_null(*last_arg))
		errors(all, BAD_MALLOC);
	command.cmd = convert_to_array(*args);
	/*
	**ALMAZ, mesto dlya tvoei function
	*/
	free_cmd(command.cmd);
	lstclear_char(args);
	if (set_new_lst(all, args, last_arg, data))
		errors(all, BAD_MALLOC);
}