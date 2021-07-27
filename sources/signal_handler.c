#include "../headers/overall.h"

void	signal_handler(int signal_code)
{
	int		status;

	wait(&status);
	if (status == SIGINT || status == SIGQUIT)
	{
		if (signal_code == SIGINT)
		{
			g_errno = 130;
			ft_putendl(NULL);
		}
		else if (signal_code == SIGQUIT)
		{
			g_errno = 131;
			ft_putstr_fd("Quit: 3\n", 1);
		}
	}
	else if ((signal_code == 2 && status != 0)
		|| (signal_code != 2 && status == 0))
	{
		write(1, "\n", 1);
		print_promt();
		tputs(save_cursor, 1, ft_putint);
	}
}
