//MAKE MORE TESTS AND WRITE IT WITH NORM
#include "../headers/overall.h"

int	backslash_double_quotes(char **arg, char **data, int *arg_size)
{
	if (*(*data + 1) == '$')
	{
		(*data)++;
		*arg = char_join(arg, **data, *arg_size);
		if (!*arg)
			return (BAD_MALLOC);														//malloc problem
	}
	else
	{
		*arg = char_join(arg, **data, *arg_size);
		if (!*arg)
			return (BAD_MALLOC);
	}
	return (ALL_OK);
}

/*if it end with '\0' and didn't clode quotes it still return argument and work but it udefined behavior*/

int	double_quotes(char **arg, char **data, int *arg_size, t_lst **env)
{
	(*data)++;
	while (**data != '\"' && **data)
	{
		if (**data == '$')																// dollar_quotes
		{
			if (dollar(arg, data, arg_size, env))
				return (BAD_MALLOC);													//don't forget about this one
			continue ;
		}
		else if (**data == '\\')
		{
			if (backslash_double_quotes(arg, data, arg_size))
				return (BAD_MALLOC);
		}
		else
		{
			*arg = char_join(arg, **data, *arg_size);
			if (!*arg)
				return (BAD_MALLOC);													//malloc problem
		}
		(*data)++;
		(*arg_size)++;
	}
	return (ALL_OK);
}

int	single_quotes(char **arg, char **data, int *arg_size)
{
	(*data)++;
	while (**data != '\'' && **data)
	{
		*arg = char_join(arg, **data, *arg_size);
		if (!*arg)
			return (BAD_MALLOC);
		(*data)++;
		(*arg_size)++;
	}
	return (ALL_OK);
}

int	special_symbol(char **arg, char **data, int *arg_size, t_lst **env)
{
	if (**data == '\"')
	{
		if (double_quotes(arg, data, arg_size, env))
			return (BAD_MALLOC);
	}
	else if (**data == '\'')
	{
		if (single_quotes(arg, data, arg_size))
			return (BAD_MALLOC);
	}
	else if (**data == '$')
	{
		if (dollar(arg, data, arg_size, env))
			return (BAD_MALLOC);
		(*data)--;
		(*arg_size)--;
	}
	return (ALL_OK);
}
