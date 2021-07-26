#include "../headers/overall.h"

static int	is_n(char *string)
{
	if (ft_strcmp(string, "-n") == 0)
		return (1);
	return (0);
}

void	ft_echo(char **args)
{
	int	flag_n;

	flag_n = is_n(*args);
	while (*args && ft_strcmp("-n", *args) == 0)
		args++;
	while (*args)
	{
		ft_putstr_fd(*args, 1);
		args++;
		if (*args)
			ft_putchar_fd(' ', 1);
	}
	if (flag_n == 1)
		ft_putchar_fd('\n', 1);
	g_errno = 0;
}
