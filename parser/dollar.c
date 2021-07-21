#include "../headers/overall.h"

int	add_g_errno(char **arg, char **data, int *arg_size)
{
	char	*gerrno;
	int		i;

	*data += 2;
	gerrno = ft_itoa(g_errno);
	if (gerrno == NULL)
		return (BAD_MALLOC);
	i = -1;
	while (gerrno[++i])
	{
		*arg = char_join(arg, *(gerrno + i), *arg_size);
		if (!*arg)
			return (BAD_MALLOC);
		(*arg_size)++;
	}
	free(gerrno);
	return (ALL_OK);
}

static int	undefine_behavior(char **data)
{
	if (*(*data + 1) == '_')
		return (0);
	if ((*(*data + 1) >= ' ' && *(*data + 1) <= '/') || (*(*data + 1) >= ':'
			&& *(*data + 1) <= 62) || *(*data + 1) == 64
		|| (*(*data + 1) >= 91 && *(*data + 1) <= 96)
		|| (*(*data + 1) >= 123 && *(*data + 1) <= 126))
	{
		return (1);
	}
	return (0);
}

static int	handle_question_and_endline(char **arg, char **data, int *arg_size)
{
	if (*(*data + 1) == '?')
	{
		if (add_g_errno(arg, data, arg_size))
			return (BAD_MALLOC);
	}
	else if (!*(*data + 1))
	{
		*arg = char_join(arg, **data, *arg_size);
		if (!*arg)
			return (BAD_MALLOC);
		(*data)++;
	}
	return (ALL_OK);
}

int	dollar(char **arg, char **data, int *arg_size, t_env_list **env)
{
	if (undefine_behavior(data))
	{
		*arg = char_join(arg, **data, *arg_size);
		if (!*arg)
			return (BAD_MALLOC);
		(*arg_size)++;
		(*data)++;
	}
	if (*(*data + 1) == '?' || !*(*data + 1))
	{
		if (handle_question_and_endline(arg, data, arg_size))
			return (BAD_MALLOC);
	}
	else
	{
		if (get_env_ergument(arg, data, arg_size, env))
			return (BAD_MALLOC);
	}
	return (ALL_OK);
}
