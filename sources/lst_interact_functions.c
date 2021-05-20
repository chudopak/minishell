#include "../headers/overall.h"

void	lst_add_back(t_lst **lst, t_lst *new)
{
	t_lst	*tmp;

	if (!*lst)
		*lst = new;
	else
	{
		tmp = *lst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

t_lst	*lstnew_char(char *content)
{
	t_lst	*tmp;

	tmp = (t_lst *)malloc(sizeof(t_lst));
	if (!tmp)
		return (NULL);
	if (!content)
		tmp->str = NULL;
	else
		tmp->str = ft_strdup(content);
	tmp->next = NULL;
	return (tmp);
}

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

int	lst_size(t_lst *lst)
{
	int		size;

	size = 0;
	while (lst)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}
