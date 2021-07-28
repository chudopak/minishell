#include "../headers/overall.h"

int	find_name_len(const char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (0);
	if (!(*str == '_' || ft_isalpha(*str)))
		return (0);
	len++;
	while (str[len] && (str[len] == '_' || ft_isalnum(str[len])))
		len++;
	return (len);
}

void	free_map(char **map)
{
	char	**tmp;

	tmp = map;
	while (*map)
	{
		free(*map);
		map++;
	}
	free(tmp);
}

static char	*for_norm1(char **splitted, t_command *command)
{
	char	*tmp;

	tmp = ft_strjoin(*splitted, "/");
	tmp = join_and_free(tmp, command->cmd[0]);
	return (tmp);
}

char	*split_path(t_all *all, t_command *command)
{
	char		**splitted;
	char		*correct_path;
	char		**tmp;
	struct stat	buf;

	correct_path = set_command_path(command->cmd[0]);
	if (correct_path)
		return (correct_path);
	splitted = ft_split(all->path, ':');
	if (!splitted)
		return (NULL);
	tmp = splitted;
	while (*splitted)
	{
		correct_path = for_norm1(splitted, command);
		if (stat(correct_path, &buf) == 0)
		{
			free_map(tmp);
			return (correct_path);
		}
		free(correct_path);
		splitted++;
	}
	free_map(tmp);
	return (NULL);
}
