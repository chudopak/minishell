#include "../headers/overall.h"

char	*char_join(char **arg, char symbol, int arg_size)
{
	char	*res;
	int		i;
	char	*tmp;

	tmp = *arg;
	res = malloc(sizeof(char) * (arg_size + 2));
	if (!res)
		return (NULL);
	i = 0;
	if (tmp)
	{
		while (i < arg_size)
		{
			res[i] = *tmp;
			i++;
			(tmp)++;
		}
	}
	res[i] = symbol;
	res[++i] = '\0';
	free(*arg);
	return (res);
}

void	free_cmd(char **cmd)
{
	char	**tmp;

	tmp = cmd;
	while (*cmd)
	{
		free(*cmd);
		cmd++;
	}
	free(tmp);
}
