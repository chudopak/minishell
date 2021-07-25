#include "../headers/overall.h"

static void	print_error(char *new_path)
{
	ft_putstr_fd("cd: ", 2);
	ft_putstr_fd((char *)new_path, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(strerror(g_errno), 2);
	ft_putstr_fd("\n", 2);
}

void	ft_cd(t_all *all, char *new_path)
{
	t_env_item	*tmp;
	char		*buf;
	char		*old_pwd;

	if (!new_path)
		new_path = ft_env_list_get_value(all->env, "HOME");
	if (chdir(new_path) == -1)
	{
		g_errno = errno;
		print_error(new_path);
		return ;
	}
	g_errno = 0;
	tmp = ft_get_env_item_with_key(all->env, "PWD");
	if (!tmp)
		return ;
	buf = getcwd(NULL, 0);
	old_pwd = tmp->value;
	tmp->value = buf;
	tmp = ft_get_env_item_with_key(all->env, "OLDPWD");
	if (!tmp)
		return (free(old_pwd));
	tmp->value = old_pwd;
}
