#include "../headers/overall.h"

void	ft_env(t_all *all)
{
	ft_env_list_print(all->env);
	g_errno = 0;
}
