#include "../headers/overall.h"

int	backslash_double_quotes(char **arg, char **data, int *arg_size)
{
	if (*(*data + 1) == '$')
	{
		(*data)++;
		*arg = char_join(arg, **data, *arg_size);
		if (!*arg)
			return (BAD_MALLOC);
	}
	else
	{
		*arg = char_join(arg, **data, *arg_size);
		if (!*arg)
			return (BAD_MALLOC);
	}
	return (ALL_OK);
}

int	back_slash(char **arg, char **data, int *arg_size)
{
	(*data)++;
	if (**data == '\0')
	{
		*arg = char_join(arg, '\\', *arg_size);
		if (!*arg)
			return (BAD_MALLOC);
	}
	else
	{
		*arg = char_join(arg, **data, *arg_size);
		if (!*arg)
			return (BAD_MALLOC);
	}
	return (ALL_OK);
}
