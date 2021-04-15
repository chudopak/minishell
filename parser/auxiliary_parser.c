/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliary_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarash <pmarash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 15:43:39 by pmarash           #+#    #+#             */
/*   Updated: 2021/04/15 18:08:50 by pmarash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/overall.h"

char	*char_join(char *arg, char symbol, int arg_size)
{
	char	*res;
	int		i;

	res = malloc(sizeof(char) * (arg_size + 2));
	if (!res)
		return (0);
	i = 0;
	if (arg)
		while (i < arg_size)
		{
			res[i] = arg[i];
			i++;
		}
	res[i] = symbol;
	res[++i] = '\0';
	return (res);
}
