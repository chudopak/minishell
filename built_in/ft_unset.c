#include "../headers/overall.h"

int		is_correct_str(const char *str)
{
	if (ft_isalpha(*str) || *str == '_')
	{
		str++;
		while (*str)
		{
			if (*str != '_' && !ft_isalnum(*str))
				return (0);
			str++;
		}
		return (1);
	}
	return (0);
}

void ft_unset(t_all *all, char **args)
{
	g_errno = 0;
	while (*args)
	{
		if (!is_correct_str(*args))
		{
			ft_putstr_fd("unset: `", 2);
			ft_putstr_fd(*args, 2);
			ft_putstr_fd("': not a valid identifier\n", 2);
			g_errno = 1;
		}
		else
			ft_env_list_remove(&all->env, *args);
		args++;
	}
}