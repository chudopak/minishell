#include "../headers/overall.h"

static void	error_id(char *str)
{
	ft_putstr_fd("export: `", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("': not a valid identifier", 2);
	g_errno = 1;
}

static int	create_new_env_arg(char *key, int id,
								  char *value, t_env_list **env_list)
{
	t_env_item	*new_item;
	t_env_list	*new_list;

	new_item = ft_env_item_new(key, id, value);
	if (!new_item)
		return (0);
	new_list = ft_env_list_new(new_item);
	if (!new_list)
	{
		ft_env_item_free(new_item);
		return (0);
	}
	ft_env_list_add_back(env_list, new_list);
	return (1);
}

static void	key_exists(t_env_list **env_list, t_env_item *item)
{
	t_env_item	*tmp_item;
	int			i;

	if (item->id == 1)
		ft_env_list_replace(*env_list, item);
	else if (item->id == 2)
	{
		tmp_item = ft_get_env_item_with_key(*env_list, item->key);
		tmp_item->value = join_and_free(tmp_item->value, item->value);
		tmp_item->id = 1;
	}
	else if (item->id == 0)
		(void)i;
	else
		ft_putstr_fd("Unknown item->identifier\n", 2);
}

void	ft_export(char **args, t_all *all)
{
	t_env_item	*item;

	g_errno = 0;
	if (!*args)
		ft_env_list_print_with_declare(all->env);
	while (*args)
	{
		item = get_env_item_from_envp_string(*args);
		if (!item)
			break ;
		if (ft_strlen(item->key) == 0 || item->id == -1)
			error_id(*args);
		else if (ft_env_key_exist(all->env, item->key))
			key_exists(&all->env, item);
		else
		{
			if (!create_new_env_arg(item->key, item->id,
					item->value, &all->env))
				break ;
		}
		args++;
		ft_env_item_free(item);
	}
}
