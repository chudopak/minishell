#include "../headers/overall.h"

void ft_export(char **args, t_all *all)
{
//	t_env_item	*item;
//
//	g_errno = 0;
	if (!*args)
		ft_env_list_print_with_declare(all->env);
	(void) all;
	while (*args)
	{
		args++;
	}
}