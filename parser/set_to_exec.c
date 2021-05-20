#include "../headers/overall.h"

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
	return (ALL_OK);
}

static void	print_command(char **cmd)
{
	printf("--------------------------\n");
	for (int i = 0; cmd[i]; i++)
		printf("%s\n", cmd[i]);
	printf("--------------------------\n");
}

int	set_to_exec(t_all *all, t_lst **args, t_lst **last_arg, char **data)
{
	t_command	command;

	command = set_token(all, **data);
	if (check_last_arg_for_null(*last_arg))
		errors("Error: malloc error in \"set_to_exec\".\n", BAD_MALLOC);
	command.cmd = convert_to_array(*args);
	print_command(command.cmd);
	if (all->redirect)
	{
		if (set_fd_for_redirect(&command))
			;
	}
	/*
		else
			**ALMAZ, mesto dlya tvoei function
	}
	else
		**ALMAZ, mesto dlya tvoei function
	*/
	clear_leftover(&command, args);
	if (set_new_lst(all, args, last_arg, data))
		errors("Error: malloc error in \"set_to_exec\".\n", BAD_MALLOC);
	return (0);
}