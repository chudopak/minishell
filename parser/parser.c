#include "../headers/overall.h"

static int	handle_space(char **data, t_lst **last_arg)
{
	t_lst	*tmp;

	tmp = lstnew_char(NULL);
	if (!tmp)
		return (1);
	lst_add_back(last_arg, tmp);
	*last_arg = (*last_arg)->next;
	while (**data == ' ')
		(*data)++;
	return (ALL_OK);
}

static void test_parsed(t_lst *args)
{
	while (args->next)
	{
		printf("%s\n", args->str);
		args = args->next;
	}
	printf("%s\n", args->str);
}


int	parser(char *data, t_lst **env)
{
	t_lst	*args;
	t_lst	*last_arg;
	int		arg_size;												// length of current argument

	if (!*data || !data)
		return (0);
	args = lstnew_char(NULL);
	last_arg = args;
	arg_size = 0;													//check how u gonna count size couse of char join
	while (*data == ' ' && *data)
		data++;
	while (*data)
	{
		if (*data == '|' || *data == ';')
			return (1);												//execve
		if (*data == '\"' || *data == '\'' 							//
				|| *data == '$' || *data == '\\')					//
		{
			if (special_symbol(&(last_arg->str), &data, &arg_size, env))	// write function here 
				return (BAD_MALLOC);
			if (!*data)
				break ;
		}
		else if (*data == ' ')
		{
			if (handle_space(&data, &last_arg) == 1)				//and don't forget about this
				return (1);											// ERROR retrun (Malloc)
			arg_size = 0;
			continue ;
		}
		else
		{
			last_arg->str = char_join(&(last_arg->str), *data, arg_size);
			if (!last_arg->str)
				return (1);											//error return (malloc)
		}
		data++;
		arg_size++;
	}
	//test_parsed(args);
	//printf("------------\n");
	//lstclear_char(&args);
	return (ALL_OK);
}
