/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vping <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 18:22:01 by vping             #+#    #+#             */
/*   Updated: 2020/11/13 16:56:57 by vping            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	char	sym;

	ptr = (char *)s + ft_strlen(s);
	sym = (char)c;
	while (ptr >= s)
	{
		if (*ptr == sym)
			return (ptr);
		ptr--;
	}
	return (NULL);
}
