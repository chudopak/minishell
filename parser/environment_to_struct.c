/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment_to_struct.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarash <pmarash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 19:11:21 by pmarash           #+#    #+#             */
/*   Updated: 2021/04/15 15:40:23 by pmarash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/overall.h"

int	environment_to_struct(t_lst **env, char **envp)
{
	t_lst	*tmp;

	while (*envp)
	{
		tmp = lstnew_char(*envp);
		if (!tmp)
		{
			lstclear_char(env);
			return (1);
		}
		lst_add_back(env, tmp);
		envp++;
	}
	return (0);
}
