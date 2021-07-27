#include "../headers/overall.h"

static int	is_n(char *string)
{
	if (ft_strncmp(string, "-n", 2) == 0)
		return (1);
	return (0);
}

void	ft_echo(char **args)
{
	int	flag_n;

	flag_n = is_n(*args);
	if (!*args)
	{
		ft_putchar_fd('\n', 1);
		return ;
	}
	while (*args && ft_strncmp("-n", *args, 2) == 0)
		args++;
	while (*args)
	{
		ft_putstr_fd(*args, 1);
		args++;
		if (*args)
			ft_putchar_fd(' ', 1);
	}
	if (!flag_n)
		ft_putchar_fd('\n', 1);
	g_errno = 0;
}
