#include "../headers/overall.h"

void	set_path(t_env_list *env, char **path)
{
	*path = ft_env_list_get_value(env, "PATH");
	if (!*path)
		errors("Error: can't find PATH.\n", PATH_MISSING);
}