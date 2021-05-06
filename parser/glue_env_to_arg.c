#include "../headers/overall.h"

int	cmp_data_to_env(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
		{
			if (((*s1 >= ' ' && *s1 <= '/') || (*s1 >= ':' && *s1 <= 64)
					|| (*s1 >= 91 && *s1 <= 96)
					|| (*s1 >= 123 && *s1 <= 126)) && *s2 == '=')
				return (0);
			else
				return (1);
		}
		s1++;
		s2++;
	}
	if (!*s1 && *s2 == '=')
		return (0);
	return (1);
}

int	add_matched_argument(char **arg, char *env_arg, int *arg_size)
{
	while (*env_arg != '=')
		env_arg++;
	env_arg++;
	while (*env_arg)
	{
		*arg = char_join(arg, *env_arg, *arg_size);
		if (!*arg)
			return (BAD_MALLOC);
		(*arg_size)++;
		env_arg++;
	}
	return (ALL_OK);
}

void	skip_unnecessary_symbols(char **data, t_lst *tmp)
{
	int		i;

	if (tmp)
	{
		i = -1;
		while ((tmp->str)[++i] == **data && *data && (tmp->str)[i])
			(*data)++;
	}
	else
	{
		i = -1;
		while ((**data >= '0' && **data <= '9')
			|| ('A' <= **data && **data <= 'Z')
			|| ('a' <= **data && **data <= 'z'))
			(*data)++;
	}
}

int	get_env_ergument(char **arg, char **data, int *arg_size, t_lst **env)
{
	t_lst	*tmp;

	(*data)++;
	tmp = *env;
	while (tmp)
	{
		if (cmp_data_to_env(*data, tmp->str) == 0)
		{
			if (add_matched_argument(arg, tmp->str, arg_size))
				return (BAD_MALLOC);
			break ;
		}
		tmp = tmp->next;
	}
	skip_unnecessary_symbols(data, tmp);
	return (ALL_OK);
}
