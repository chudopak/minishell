#include "../headers/overall.h"

void	push_writen_in_history(t_all *all)
{
	int		fd;

	fd = open(".history.txt", O_WRONLY | O_APPEND | O_CREAT, S_IRWXU);
	if (fd < 0)
		;
	else
	{
		if (all->current_cmd->cmd)
		{
			write(fd, all->current_cmd->cmd, ft_strlen(all->current_cmd->cmd));
			write(fd, "\n", 1);
		}
		close(fd);
	}
}

void	set_head_of_history(t_all *all)
{
	t_history	*tmp;

	tmp = malloc(sizeof(t_history));
	if (!tmp)
		errors("Error: malloc error in \"set hisoty\".\n", BAD_MALLOC);
	tmp->next = NULL;
	tmp->cmd = NULL;
	tmp->prev = NULL;
	all->head_history = tmp;
	all->current_cmd = tmp;
}

void	new_history_elem(t_all *all)
{
	t_history	*new_node;

	if (all->cmd_in_history > HISTORY_LIMIT)
		rm_node(all);
	new_node = malloc(sizeof(t_history));
	if (!new_node)
		errors("Error: malloc error in \"new_history_elem\".\n", BAD_MALLOC);
	new_node->prev = all->current_cmd;
	new_node->cmd = NULL;
	new_node->next = NULL;
	all->current_cmd->next = new_node;
	all->current_cmd = new_node;
	all->cmd_in_history++;
	all->stroller = all->current_cmd;
}

void	set_history(t_all *all)
{
	int		fd;
	char	*line;

	line = NULL;
	set_head_of_history(all);
	fd = open(".history.txt", O_RDONLY);
	if (fd < 0)
		return ;
	while (get_next_line(fd, &line) > 0)
	{
		new_history_elem(all);
		if (line)
			all->current_cmd->cmd = ft_strdup(line);
		free(line);
		line = NULL;
	}
	if (line && ft_strlen(line))
	{
		new_history_elem(all);
		all->current_cmd->cmd = ft_strdup(line);
	}
	free(line);
	close(fd);
}
