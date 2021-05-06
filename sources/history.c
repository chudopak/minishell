#include "../headers/overall.h"

static void	history_prev(t_all *all)
{
	t_history	*tmp;

	tmp = all->stroller;
	if (tmp->prev)
	{
		tmp = tmp->prev;
		while (!tmp->cmd && tmp->prev)
			tmp = tmp->prev;
		if (tmp->cmd)
		{
			all->stroller = tmp;
			tputs(restore_cursor, 1, ft_putint);
			tputs(tigetstr("ed"), 1, ft_putint);
			ft_putstr_fd(all->stroller->cmd, 1);
			all->cursor_pos = ft_strlen(all->stroller->cmd);
			all->writen_symblos = all->cursor_pos;
		}
	}
}

static void	history_next(t_all *all)
{
	if (all->stroller->next)
	{
		all->stroller = all->stroller->next;
		while (!all->stroller->cmd && all->stroller->next)
			all->stroller = all->stroller->next;
		if (all->stroller->cmd)
		{
			tputs(restore_cursor, 1, ft_putint);
			tputs(tigetstr("ed"), 1, ft_putint);
			ft_putstr_fd(all->stroller->cmd, 1);
			all->cursor_pos = ft_strlen(all->stroller->cmd);
			all->writen_symblos = all->cursor_pos;
		}
		else
		{
			tputs(restore_cursor, 1, ft_putint);
			tputs(tigetstr("ed"), 1, ft_putint);
			ft_putstr_fd(all->stroller->cmd, 1);
			all->cursor_pos = 0;
			all->writen_symblos = 0;
		}
	}
}

void	get_history_comand(t_all *all, char *str)
{
	if (!all->stroller->next && !ft_strcmp(str, "\e[B"))
		return ;
	if (!ft_strcmp(str, "\e[A"))
		history_prev(all);
	else
		history_next(all);
}
