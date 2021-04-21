#include "../headers/overall.h"

static int	handle_space(char **data, t_lst **last_arg)
{
	t_lst	*tmp;
	char	*tmp_str;

	tmp_str = *data;
	while (*tmp_str == ' ')
		tmp_str++;
	if (*tmp_str)
	{
		tmp = lstnew_char(NULL);
		if (!tmp)
			return (BAD_MALLOC);
		lst_add_back(last_arg, tmp);
		*last_arg = (*last_arg)->next;
	}
	while (*(*data + 1) == ' ')
		(*data)++;
	return (ALL_OK);
}

static int	handle_arrows(char **data, t_lst **last_arg)
{
	t_lst	*tmp;
	int		arg_size;

	if ((*last_arg)->str)
	{
		tmp = lstnew_char(NULL);
		if (!tmp)
			return (BAD_MALLOC);
		lst_add_back(last_arg, tmp);
		*last_arg = (*last_arg)->next;
	}
	arg_size = 0;
	while (**data == '<' || **data == '>')
	{
		(*last_arg)->str = char_join(&((*last_arg)->str), **data, arg_size);
		if (!(*last_arg)->str)
			return (BAD_MALLOC);
		++*data;
		arg_size++;
	}
	if (**data != ' ' && **data)
	{
		tmp = lstnew_char(NULL);
		if (!tmp)
			return (BAD_MALLOC);
		lst_add_back(last_arg, tmp);
		*last_arg = (*last_arg)->next;
	}
	(*data)--;
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
		else if (*data == '>' || *data == '<')
		{
			if (handle_arrows(&data, &last_arg) == 1)
				return (BAD_MALLOC);
			arg_size = -1;
		}
		else if (*data == ' ')
		{
			if (handle_space(&data, &last_arg) == 1)				//and don't forget about this
				return (BAD_MALLOC);								// ERROR retrun (Malloc)
			arg_size = -1;
		}
		else
		{
			last_arg->str = char_join(&(last_arg->str), *data, arg_size);
			if (!last_arg->str)
				return (BAD_MALLOC);								//error return (malloc)
		}
		data++;
		arg_size++;
	}
	test_parsed(args);
	printf("------------\n");
	lstclear_char(&args);
	return (ALL_OK);
}
