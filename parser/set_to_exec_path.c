#include "../headers/overall.h"

int	argument_is_absolut_path(char *arg)
{
	if (arg[0] == '/')
		return (1);
	return (0);
}

int	argument_is_relative_path(char *arg)
{
	if (arg[0] != '/' && ft_strchr(arg, '/'))
		return (1);
	return (0);
}

char	*set_command_path(char *arg)
{
	if (argument_is_absolut_path(arg))
		return (ft_strdup(arg));
	if (argument_is_relative_path(arg))
		return (ft_strjoin("./", arg));
	return (NULL);
}
