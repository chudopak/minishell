#include "../../headers/overall.h"

int	which_id(const char *str)
{
	if (*str == '\0')
		return (0);
	if (*str == '=')
		return (1);
	if (*str == '+' && *(str + 1) == '=')
		return (2);
	return (-1);
}

t_env_item	*get_env_item_from_envp_string(const char *envp_string)
{
	int			i;
	t_env_item	*item;

	item = ft_env_item_new(NULL, 0, NULL);
	if (!item)
		return (NULL);
	i = find_name_len(envp_string);
	item->key = ft_strndup(envp_string, i);
	item->identifier = which_id(envp_string + i);
	if (item->identifier != -1)
		item->value = ft_strdup(envp_string + i + item->identifier);
	return (item);
}

t_env_list	*ft_envp_to_env_list(char **envp)
{
	t_env_list	*env_list;
	t_env_item	*env_item;
	t_env_list	*tmp_list;

	env_list = NULL;
	if (envp == NULL)
		return (NULL);
	while (*envp)
	{
		env_item = get_env_item_from_envp_string(*envp);
		if (!env_item)
			break ;
		tmp_list = ft_env_list_new(env_item);
		if (!tmp_list)
		{
			ft_env_item_free(env_item);
			break ;
		}
		ft_env_list_add_back(&env_list, tmp_list);
		envp++;
	}
	return (env_list);
}