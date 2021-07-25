#include "../../headers/overall.h"

t_env_list	*ft_env_list_copy(t_env_list *list)
{
	t_env_list	*copy_list;
	t_env_item	*item;
	t_env_list	*node;

	copy_list = NULL;
	while (list)
	{
		item = ft_env_item_new(list->item->key, list->item->id,
				list->item->value);
		node = ft_env_list_new(item);
		ft_env_list_add_back(&copy_list, node);
		list = list->next;
	}
	return (copy_list);
}

char	*ft_env_list_get_value(t_env_list *env_list, char *key)
{
	while (env_list)
	{
		if ((ft_strcmp(env_list->item->key, key)) == 0)
			return (env_list->item->value);
		env_list = env_list->next;
	}
	return (NULL);
}

int	ft_env_list_len(t_env_list *env_list)
{
	int		len;

	len = 0;
	if (env_list == NULL)
		return (0);
	while (env_list)
	{
		len++;
		env_list = env_list->next;
	}
	return (len);
}

t_env_list	*ft_env_list_new(t_env_item *env_item)
{
	t_env_list	*node;

	node = malloc(sizeof(t_env_list));
	if (!node)
		return (NULL);
	node->item = env_item;
	node->next = 0;
	return (node);
}

int	ft_env_list_remove(t_env_list **list, char *key)
{
	t_env_list	*node;
	t_env_list	*temp;
	t_env_list	*prev;

	node = *list;
	prev = NULL;
	while (node)
	{
		if (ft_strcmp(node->item->key, key) == 0)
		{
			ft_env_item_del(node->item);
			temp = node;
			if (prev)
				prev->next = node->next;
			else
				*list = node->next;
			free(temp);
			return (1);
		}
		prev = node;
		node = node->next;
	}
	return (0);
}
