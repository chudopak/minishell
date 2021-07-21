#include "../../headers/overall.h"

void	ft_env_item_free(t_env_item *item)
{
	free(item->key);
	free(item->value);
	free(item);
}

t_env_item	*ft_env_item_new(char *key, int id, char *value)
{
	t_env_item	*item;

	item = malloc(sizeof(t_env_item));
	if (!item)
		return (NULL);
	item->key = ft_strdup(key);
	item->id = id;
	item->value = ft_strdup(value);
	return (item);
}

void	ft_env_list_add_back(t_env_list **env_list, t_env_list *new)
{
	t_env_list	*node;

	node = *env_list;
	if (!*env_list)
	{
		*env_list = new;
		return ;
	}
	if (!new)
		return ;
	while (node->next)
		node = node->next;
	node->next = new;
}

void	ft_env_item_del(t_env_item *item)
{
	free(item->key);
	free(item->value);
	free(item);
}

void	ft_env_list_clear(t_env_list **lst)
{
	t_env_list	*node;
	t_env_list	*temp;

	node = *lst;
	if (!*lst)
		return ;
	while (node)
	{
		ft_env_item_del(node->item);
		temp = node;
		node = node->next;
		free(temp);
	}
	*lst = NULL;
}