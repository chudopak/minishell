#include "../headers/overall.h"

void	lstclear_char(t_lst **lst)
{
	t_lst	*tmp;

	if (*lst)
	{
		tmp = *lst;
		while (tmp)
		{
			tmp = tmp->next;
			free((*lst)->str);
			free(*lst);
			*lst = tmp;
		}
		*lst = NULL;
	}
}
