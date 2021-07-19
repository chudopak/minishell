#include "../headers/overall.h"

void ft_cd(t_all *all, char *new_path)
{
	t_env_list	*tmp;
	char 		*buf;
	char 		*old_pwd;

	if (!new_path)
		new_path = ft_env_list_get_value(*list, "HOME");
	if (chdir(new_path) == -1)
	{
		g_errno = errno;
		return ;
	}
	tmp = ft_get_env_item
}