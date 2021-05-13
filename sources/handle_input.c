#include "../headers/overall.h"

char	*delete_symbol(t_all *all)
{
	char	*res;
	int		i;

	res = malloc(sizeof(char) * (all->writen_symblos - 1));
	if (!res)
		return (NULL);
	i = -1;
	while (++i < all->writen_symblos - 1)
		res[i] = all->stroller->cmd[i];
	res[i] = '\0';
	free(all->stroller->cmd);
	all->writen_symblos -= 1;
	return (res);
}

/*
** don't forget win size changing
*/

void	manage_backspace(t_all *all)
{
	//TIOCGWINSZ ioctl struct winsize win
	if (!all->stroller->cmd || !*(all->stroller->cmd))
		return ;
	all->stroller->cmd = delete_symbol(all);
	tputs(restore_cursor, 1, ft_putint);
	tputs(tigetstr("ed"), 1, ft_putint);
	ft_putstr_fd(all->stroller->cmd, 1);
	if (!all->stroller->cmd)
		errors(all, BAD_MALLOC);
}

static void	new_history_elem(t_all *all)
{
	t_history	*new_node;

	if (all->cmd_in_history > HISTORY_LIMIT)
		rm_node(all);
	new_node = malloc(sizeof(t_history));
	if (!new_node)
		errors(all, BAD_MALLOC);
	new_node->prev = all->current_cmd;
	new_node->cmd = NULL;
	new_node->next = NULL;
	all->current_cmd->next = new_node;
	all->current_cmd = new_node;
	all->cmd_in_history++;
	all->stroller = all->current_cmd;
}

static void	prepare_parsing(t_all *all)
{
	all->writen_symblos = 0;
	all->cursor_pos = 0;
	if (all->stroller != all->current_cmd)
	{
		free(all->current_cmd->cmd);
		all->current_cmd->cmd = ft_strdup(all->stroller->cmd);
	}
	all->stroller = NULL;
	write(1, "\n", 1);
	
	if (all->current_cmd->cmd && !syntax_error_checker(all->current_cmd->cmd))
		parser(all->current_cmd->cmd, all);
}


static void	set_char(t_all *all, char *str)
{
	all->stroller->cmd = char_join(&all->stroller->cmd,
			*str, all->writen_symblos);
	all->writen_symblos++;
	write(1, str, 1);
	all->cursor_pos++;
}

void	handle_input(t_all *all)
{
	char	str[50];
	int		readed;

	new_history_elem(all);
	while (1)
	{
		readed = read(0, str, 100);
		str[readed] = '\0';
		if (!ft_strcmp(str, "\e[A") || !ft_strcmp(str, "\e[B"))
			get_history_comand(all, str);
		else if (!ft_strcmp(str, "\3"))
			handle_ctrl_c(all);												//fix segfolt
		else if (!ft_strcmp(str, "\4"))
			exit(g_errno);													//don't forget ctrl d
		else if (!ft_strcmp(str, "\177") || *str == '\b')
			manage_backspace(all);
		else if (unprint_symbols(str))
			continue ;
		else if (ft_strcmp(str, "\n"))
			set_char(all, str);
		else
			break ;
	}
	prepare_parsing(all);
}
