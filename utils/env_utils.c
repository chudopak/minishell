#include "../headers/overall.h"

t_env_item	*new_env_item(char *key, int id, char *value)
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

t_env_list	*new_env_list(t_env_item *env_item)
{
	t_env_list	*node;

	node = malloc(sizeof(t_env_list));
	if (!node)
		return (NULL);
	node->item = env_item;
	node->next = 0;
	return (node);
}

void	env_list_add_back(t_env_list **env_list, t_env_list *new)
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

void	free_env_item(t_env_item *item)
{
	free(item->key);
	free(item->value);
	free(item);
}
