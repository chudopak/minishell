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

static void	free_map(char **map)
{
	while (*map)
	{
		free(*map);
		map++;
	}
}

char	*split_path(t_all *all, t_command *command)
{
	char		**splitted;
	char		*correct_path;
	struct stat	buf;

	splitted = ft_split(all->path, ':');
	if (!splitted)
		return (NULL);
	while (*splitted)
	{
		correct_path = ft_strjoin(*splitted, "/");
		correct_path = ft_strjoin(correct_path, command->cmd[0]);
		if (stat(correct_path, &buf) == 0)
		{
			free_map(splitted);
			return (correct_path);
		}
		splitted++;
	}
	free(correct_path);
	return (NULL);
}
