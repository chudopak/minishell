#include "../headers/overall.h"

void	handle_ctrl_c(t_all *all)
{
	if (all->stroller->cmd)
	{
		ft_putchar_fd('\n', 1);
		if (!all->stroller->next)
		{
			remove_elem_history(all);
			all->cursor_pos = 0;
			all->writen_symblos = 0;
		}
		else
		{
			all->stroller = all->current_cmd;
			if (all->stroller->cmd)
			{
				remove_elem_history(all);
				all->cursor_pos = 0;
				all->writen_symblos = 0;
			}
		}
	}
	else
		ft_putchar_fd('\n', 1);
	tputs(save_cursor, 1, ft_putint);
}

void	handle_ctrl_d(void)
{
	write(2, "exit\n", 5);
	exit(g_errno);
}
