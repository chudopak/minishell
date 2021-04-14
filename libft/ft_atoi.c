/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vping <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 15:48:18 by vping             #+#    #+#             */
/*   Updated: 2021/04/13 19:06:19 by vping            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *arr)
{
	int	sign;
	int	res;

	res = 0;
	sign = 1;
	while (*arr == ' ' || *arr == '\t' || *arr == '\v' || *arr == '\f'
		|| *arr == '\r' || *arr == '\n')
		arr++;
	if (*arr == '-' || *arr == '+')
	{
		if (*arr == '-')
			sign = -1;
		arr++;
	}
	while (*arr >= '0' && *arr <= '9')
	{
		res = res * 10 + (*arr - '0');
		arr++;
	}
	return (sign * res);
}
