/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vping <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 18:47:48 by vping             #+#    #+#             */
/*   Updated: 2021/04/13 19:58:21 by vping            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	char	*h;
	size_t	s2_len;
	size_t	i;
	size_t	j;

	h = (char *)s1;
	s2_len = ft_strlen(s2);
	if (!s2_len)
		return (h);
	if (ft_strlen(s1) < s2_len || n < s2_len)
		return (NULL);
	i = 0;
	while (h[i] && i <= n - s2_len)
	{
		j = 0;
		while (s2[j] && s2[j] == h[i + j])
			j++;
		if (j == s2_len)
			return (&h[i]);
		i++;
	}
	return (NULL);
}
