#include "../headers/overall.h"

int	unprint_symbols(char *str)
{
	if (*str < 32 && (*str != '\n' && *str != 3 && *str != 4))
		return (1);
	return (0);
}

void	rm_node(t_all *all)
{
	t_history	*tmp;

	tmp = all->head_history->next;
	tmp->prev = NULL;
	free(all->head_history);
	all->head_history = tmp;
	all->cmd_in_history--;
}

void	new_history_elem(t_all *all)
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

void	handle_ctrl_c(t_all *all)
{
	if (all->stroller->cmd)
	{
		tputs(tigetstr("ed"), 1, ft_putint);
		tputs(restore_cursor, 1, ft_putint);
		ft_putstr_fd(all->stroller->cmd, 1);
		ft_putchar_fd('\n', 1);
		free(all->stroller->cmd);
		all->stroller->cmd = NULL;
		all->current_cmd = 0;
		all->writen_symblos = 0;
	}
	else
		ft_putchar_fd('\n', 1);
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
			//write(1, "ctrl_c", ft_strlen("ctrl_c"));						//don't forget
		else if (!ft_strcmp(str, "\4"))
			exit(g_errno);													//don't forget ctrl d
		//else if (!ft_strcmp(str, "\177") || *str == '\b')
		//	backspase();
		else if (unprint_symbols(str))
			continue ;
		else if (ft_strcmp(str, "\n"))
		{
			all->stroller->cmd = char_join(&all->stroller->cmd,
					*str, all->writen_symblos);
			all->writen_symblos++;
			write(1, str, 1);
			all->cursor_pos++;
		}
		else
			break ;
	}
	all->writen_symblos = 0;
	if (all->stroller != all->current_cmd)
	{
		free(all->current_cmd->cmd);
		all->current_cmd->cmd = ft_strdup(all->stroller->cmd);
	}
	all->stroller = NULL;
	parser(all->current_cmd->cmd, all);
}
