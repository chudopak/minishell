/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstnew.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarash <pmarash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 19:27:43 by pmarash           #+#    #+#             */
/*   Updated: 2021/04/19 18:45:43 by pmarash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
