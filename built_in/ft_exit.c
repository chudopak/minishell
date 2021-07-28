#include "../headers/overall.h"

static int	is_numeral(char *str)
{
	int	i;

	i = 0;
	while (ft_isdigit(str[i]) && str[i] != '\0')
	{
		i++;
		if (str[i + 1] == '\0')
			return (1);
	}
	return (0);
}

static int	args_len(char **args)
{
	int	len;

	len = 0;
	while (args[len])
		len++;
	return (len);
}

void	ft_exit(char **args)
{
	ft_putstr_fd("exit\n", 2);
	if (!*args || !args)
		exit(g_errno);
	if (args_len(args) > 1)
	{
		ft_putstr_fd("exit: too many arguments\n", 2);
		g_errno = 1;
		return ;
	}
	if (*args && !is_numeral(*args))
	{
		ft_putstr_fd("exit: ", 2);
		ft_putstr_fd(*args, 2);
		ft_putstr_fd(": numeric argument required\n", 2);
		g_errno = 1;
		exit(255);
	}
	if (*args && is_numeral(*args))
		exit(ft_atoi(*args));
}
