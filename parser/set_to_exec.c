#include "../headers/overall.h"

static	int	actual_list_size(t_lst	*args)
{
	int		size;

	size = 0;
	while (args)
	{
		if (args->str[0] == '>' || args->str[0] == '<')
			return (size);
		else if (args->str[0])
			size++;
		args = args->next;
	}
	return (size);
}

static	char	**convert_to_array(t_lst *args)
{
	int		size;
	int		i;
	char	**arguments;

	size = actual_list_size(args);
	arguments = malloc(sizeof(char *) * (size + 1));
	arguments[size] = NULL;
	i = 0;
	while (i < size)
	{
		if (args->str[0])
		{
			arguments[i] = ft_strdup(args->str);
			i++;
		}
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

static void	print_command(char **cmd, t_command *command)
{
	(void )cmd;
	(void )command;
//	printf("--------------------------\n");
//	for (int i = 0; command->cmd[i]; i++)
//		printf("%s\n", command->cmd[i]);
//	printf("pipeout = %d\n", command->pipeout);
//	printf("pipein = %d\n", command->pipein);
//	printf("--------------------------\n");
}

int	set_to_exec(t_all *all, t_lst **args, t_lst **last_arg, char **data)
{
	t_command	command;

	command = set_token(all, **data);
	if (check_last_arg_for_null(*last_arg))
		errors("Error: malloc error in \"set_to_exec\".\n", BAD_MALLOC);
	command.cmd = convert_to_array(*args);
	print_command(command.cmd, &command);
	if (all->redirect)
	{
		if (set_fd_for_redirect(*args, &command))
			;
		else
			distribution_to_exec(all, &command);
	}
	else
		distribution_to_exec(all, &command);
	clear_leftover(&command, args);
	if (set_new_lst(all, args, last_arg, data))
		errors("Error: malloc error in \"set_to_exec\".\n", BAD_MALLOC);
	return (0);
}