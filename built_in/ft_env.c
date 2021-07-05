#include "../headers/overall.h"

void ft_env(t_all *all)
{
	while(all->env != NULL)
	{
		ft_putstr_fd(all->env->str, 1);
		ft_putchar_fd('\n', 1);
		all->env = all->env->next;
	}
	g_errno = 0;
}