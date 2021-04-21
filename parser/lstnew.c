#include "../headers/overall.h"

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
