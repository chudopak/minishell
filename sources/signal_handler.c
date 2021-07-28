#include "../headers/overall.h"

void	signal_handler(int signal_code)
{
	if (signal_code == SIGINT)
	{
		g_errno = 130;
		write(1, "\n", 1);
		ft_putendl(NULL);
	}
	else if (signal_code == SIGQUIT)
	{
		g_errno = 131;
		ft_putstr_fd("Quit: 3\n", 1);
	}
	else
		ft_putstr_fd("\n", 1);
}
