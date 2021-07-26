#include "../headers/overall.h"

static int	find_key_len(const char *envp_str)
{
	int		len;

	len = 0;
	if (!envp_str)
		return (0);
	if (!(*envp_str == '_' || ft_isalpha(*envp_str)))
		return (0);
	len++;
	while (envp_str[len] && (envp_str[len] == '_' || ft_isalnum(envp_str[len])))
		len++;
	return (len);
}

int	set_id(const char *envp_str)
{
	if (*envp_str == '\0')
		return (0);
	if (*envp_str == '=')
		return (1);
	if (*envp_str == '+' && *(envp_str + 1) == '=')
		return (2);
	return (-1);
}

static t_env_item	*get_env_item(const char *envp_str)
{
	int			key_len;
	t_env_item	*item;

	item = new_env_item(NULL, -1, NULL);
	if (!item)
		return (NULL);
	key_len = find_key_len(envp_str);
	item->key = ft_strndup(envp_str, key_len);
	item->id = set_id(envp_str + key_len);
	if (item->id != -1)
		item->value = ft_strdup(envp_str + key_len + item->id);
	return (item);
}

void	environment_to_struct(t_env_list **env, char **envp)
{
	t_env_item	*env_item;
	t_env_list	*tmp_list;

	*env = NULL;
	if (envp == NULL)
		return ;
	while (*envp)
	{
		env_item = get_env_item(*envp);
		if (env_item == NULL)
			errors("Error: malloc error in \"environment_to_struct\".\n",
				BAD_MALLOC);
		tmp_list = new_env_list(env_item);
		if (!tmp_list)
		{
			free_env_item(env_item);
			errors("Error: malloc error in \"environment_to_struct\".\n",
				BAD_MALLOC);
		}
		env_list_add_back(env, tmp_list);
		envp++;
	}
}
