#include "../headers/overall.h"

int	what_is_after_qoutes(char **data, int *arg_size, char **arg)
{
	if (*(*data + 1) != ' ' && *(*data + 1) != '\0')
		(*arg_size)--;
	else if (!*arg_size && (*(*data + 1) == ' ' || *(*data + 1) == '\0'))
	{
		*arg = char_join(arg, '\0', *arg_size);
		if (!*arg)
			return (BAD_MALLOC);
	}
	return (ALL_OK);
}

/*   if it end with '\0' and didn't clode quotes it still **
**   return argument and work but it udefined behavior    */

int	double_quotes(char **arg, char **data, int *arg_size, t_lst **env)
{
	(*data)++;
	while (**data != '\"' && **data)
	{
		if (**data == '$')
		{
			if (dollar(arg, data, arg_size, env))
				return (BAD_MALLOC);
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
				return (BAD_MALLOC);
		}
		(*data)++;
		(*arg_size)++;
	}
	what_is_after_qoutes(data, arg_size, arg);
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
	if (what_is_after_qoutes(data, arg_size, arg))
		return (BAD_MALLOC);
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
	else if (**data == '\\')
	{
		if (back_slash(arg, data, arg_size))
			return (BAD_MALLOC);
	}
	if (!**data)
		(*data)--;
	return (ALL_OK);
}
