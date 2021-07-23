# include "../../headers/overall.h"

t_env_item	*get_env_item_from_envp_string(const char *envp_string)
{
	int			i;
	t_env_item	*item;

	item = ft_env_item_new(NULL, 0, NULL);
	if (!item)
		return (NULL);
	i = find_name_len(envp_string);
	item->key = ft_strndup(envp_string, i);
	item->id = set_id(envp_string + i);
	if (item->id != -1)
		item->value = ft_strdup(envp_string + i + item->id);
	return (item);
}

int ft_env_key_exist(t_env_list *list, char *key)
{
	while (list)
	{
		if (ft_strcmp(list->item->key, key) == 0)
			return (1);
		list = list->next;
	}
	return (0);
}

void	ft_env_list_replace(t_env_list *list, t_env_item *new_item)
{
	while (list)
	{
		if (ft_strcmp(list->item->key, new_item->key) == 0)
		{
			free(list->item->value);
			list->item->value = ft_strdup(new_item->value);
			list->item->id = new_item->id;
			break ;
		}
		list = list->next;
	}
}