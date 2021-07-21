#include "../../headers/overall.h"

t_env_item	*ft_get_env_item_with_key(t_env_list *list, char *key)
{
	while (list)
	{
		if (ft_strcmp(list->item->key, key) == 0)
			return (list->item);
		list = list->next;
	}
	return (NULL);
}