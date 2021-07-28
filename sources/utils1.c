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
	if (all->head_history->cmd)
		free(all->head_history->cmd);
	free(all->head_history);
	all->head_history = tmp;
	all->cmd_in_history--;
}

void	remove_elem_history(t_all *all)
{
	free(all->stroller->cmd);
	all->stroller->cmd = NULL;
}

int	is_separator(char c)
{
	if (ft_strchr(" \t\r", c))
		return (1);
	return (0);
}
