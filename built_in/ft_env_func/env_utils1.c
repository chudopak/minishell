#include "../../headers/overall.h"

void	ft_env_item_free(t_env_item *item)
{
	free(item->key);
	free(item->value);
	free(item);
}