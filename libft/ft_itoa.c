/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 13:46:09 by ckrommen          #+#    #+#             */
/*   Updated: 2021/04/13 19:50:07 by vping            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	calculate(int *sign, int *nbr)
{
	int	lenght;

	lenght = 1;
	while (*sign >= 9 || *sign <= -9)
	{
		*sign /= 10;
		lenght += 1;
	}
	if (*nbr < 0)
	{
		*sign = 1;
		lenght += 1;
	}
	else
		*sign = 0;
	return (lenght);
}

char	*ft_itoa(int nbr)
{
	int		length;
	int		sign;
	char	*str;

	sign = nbr;
	if (nbr == -2147483648)
		return (str = ft_strdup("-2147483648"));
	length = calculate(&sign, &nbr);
	str = ft_strnew(length);
	if (!str)
		return (NULL);
	if (sign)
		str[0] = '-';
	if (nbr < 0)
		nbr *= -1;
	while (--length >= sign)
	{
		if (nbr >= 10)
			str[length] = (nbr % 10) + 48;
		else
			str[length] = nbr + 48;
		nbr /= 10;
	}
	str[ft_strlen(str)] = '\0';
	return (str);
}
