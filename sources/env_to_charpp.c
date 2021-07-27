#include "../headers/overall.h"

int	ft_env_list_size(t_env_list *lst)
{
	int		size;

	size = 0;
	while (lst)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}

static char	*env_item_to_str(t_env_item *item)
{
	char 	*string;
	size_t	i;
	size_t	count;

	i = -1;
	count = ft_strlen(item->key) + ft_strlen(item->value) + 1;
	string = malloc(sizeof (char) * (count + 1));
	if (!string)
		return (NULL);
	while (++i < ft_strlen(item->key))
		string[i] = item->key[i];
	string[i++] = '=';
	while (++i < count)
		string[i] = item->value[i - ft_strlen(item->key) - 1];
	string[i] = '\0';
	return (string);
}

char	**env_to_charpp(t_all *all)
{
	char	**tmp;
	int		len_of_list;
	int 	i;

	i = 0;
	if (all->envp_copy != NULL)
		free_map(all->envp_copy);
	len_of_list = ft_env_list_size(all->env);
	tmp = (char **)malloc((sizeof (char *) * len_of_list + 1));
	if (!tmp)
		return (NULL);
	while (all->env)
	{
		tmp[i] = env_item_to_str(all->env->item);
		if (!tmp[i])
		{
			while (i >= 0)
				free(tmp[i--]);
			return (NULL);
		}
		i++;
		all->env = all->env->next;
	}
	tmp[len_of_list] = NULL;
	return (tmp);
}