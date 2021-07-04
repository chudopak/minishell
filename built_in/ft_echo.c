# include "../headers/overall.h"

static int	check_n(char *str)
{
	if (ft_strcmp(str, "-n"))
		return (1);
	return (0);
}

void ft_echo(char **args)
{
	int check;

	if (!args || !*args)
	{
		ft_putchar_fd('\n', 1);
		return ;
	}
	check = check_n(*args);
	while (*args && ft_strcmp("-n", *args) == 0)
		args++;
	while (*args)
	{
		ft_putstr_fd(*args, 1);
		args++;
		if (*args)
			ft_putchar_fd(' ', 1);
	}
	if (!check)
		write(1, "\n", 1);
}