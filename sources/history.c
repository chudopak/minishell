#include "../headers/overall.h"

static void	history_prev(t_all *all)
{
	if (all->stroller->prev)
	{
		all->stroller = all->stroller->prev;
		while (!all->stroller->cmd && all->stroller->prev)
			all->stroller = all->stroller->prev;
		if (all->stroller->cmd)
		{
			tputs(restore_cursor, 1, ft_putint);
			tputs(tigetstr("ed"), 1, ft_putint);
			ft_putstr_fd(all->stroller->cmd, 1);
			all->cursor_pos = ft_strlen(all->stroller->cmd);
			all->writen_symblos = all->cursor_pos;
			free(all->current_cmd->cmd);
			all->current_cmd->cmd = ft_strdup(all->stroller->cmd);
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
			free(all->current_cmd->cmd);
			all->current_cmd->cmd = ft_strdup(all->stroller->cmd);
		}
		if (all->stroller == all->current_cmd)
		{
			tputs(restore_cursor, 1, ft_putint);
			tputs(tigetstr("ed"), 1, ft_putint);
			all->cursor_pos = 0;
			all->writen_symblos = 0;
			free(all->current_cmd->cmd);
			all->current_cmd->cmd = NULL;
		}
	}
}

void	get_history_comand(t_all *all, char *str)
{
	if (!all->stroller && !ft_strcmp(str, "\e[B"))
		return ;
	if (!all->stroller)
		all->stroller = all->current_cmd;
	if (!ft_strcmp(str, "\e[A"))
		history_prev(all);
	else
		history_next(all);
}
