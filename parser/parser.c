#include "../headers/overall.h"

//static void test_parsed(t_lst *args)
//{
//	while (args->next)
//	{
//		printf("%s\n", args->str);
//		args = args->next;
//	}
//	printf("%s\n", args->str);
//}

static void	handle_space_arrow(t_all *all, char **data,
							t_lst **last_arg, int *arg_size)
{
	int		status;

	if (**data == '>' || **data == '<')
	{
		status = handle_arrows(all, data, last_arg);
		if (status)
			errors(all, status);
		*arg_size = -1;
	}
	else if (**data == ' ')
	{
		if (handle_space(data, last_arg) == 1)
			errors(all, BAD_MALLOC);
		*arg_size = -1;
	}
}

static void	handle_special_symbol(t_all *all, char **arg,
								char **data, int *arg_size)
{
	if (special_symbol(arg, data, arg_size, &all->env))
		errors(all, BAD_MALLOC);
}

static void	add_usual_symbol(t_all *all, t_lst **last_arg,
							char **data, int *arg_size)
{
	(*last_arg)->str = char_join(&(*last_arg)->str, **data, *arg_size);
	if (!(*last_arg)->str)
		errors(all, BAD_MALLOC);
}

static void	set_for_parsing(t_lst **args, t_lst **last_arg,
							int *arg_size, char **data)
{
	*args = lstnew_char(NULL);
	*last_arg = *args;
	*arg_size = 0;
	while (**data == ' ' && **data)
		(*data)++;
}

static void	prepare_to_exec(t_all *all, t_lst **args, t_lst **last_arg, char **data)
{
	if ((*last_arg)->str == NULL)
		put_endline(last_arg);
	set_to_exec(all, args, last_arg, data);
}

int	parser(char *data, t_all *all)
{
	t_lst	*args;
	t_lst	*last_arg;
	int		arg_size;												// length of current argument

	if (!data || !*data)
		return (ALL_OK);
	set_for_parsing(&args, &last_arg, &arg_size, &data);
	while (!ft_strchr("\n\0#", *data))
	{
		if (*data == '|' || *data == ';')
			set_to_exec(all, &args, &last_arg, &data);
		if (*data == '\"' || *data == '\'' || *data == '$' || *data == '\\')
			handle_special_symbol(all, &(last_arg->str), &data, &arg_size);
		else if (*data == '>' || *data == '<' || *data == ' ')
			handle_space_arrow(all, &data, &last_arg, &arg_size);
		else
			add_usual_symbol(all, &last_arg, &data, &arg_size);
		data++;
		arg_size++;
	}
	prepare_to_exec(all, &args, &last_arg, &data);
	//printf("------------\n");
	//test_parsed(args);
	//printf("------------\n");
	return (ALL_OK);
}
