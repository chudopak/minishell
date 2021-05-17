/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarash <pmarash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 16:58:51 by pmarash           #+#    #+#             */
/*   Updated: 2020/11/21 17:33:18 by pmarash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char		*ft_strdup(const char *s1)
{
	int		i;
	char	*s2;

	if (!(s2 = (char*)malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

void		*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned int	i;
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char*)dst;
	s = (unsigned char*)src;
	if (!d && !s)
		return (0);
	if (s < d)
		while (n-- > 0)
			d[n] = s[n];
	else
	{
		i = -1;
		while (++i < n)
			d[i] = s[i];
	}
	return (dst);
}

char		*ft_substr(char const *s, int start, int len)
{
	char	*str;
	int		i;

	if (!s)
		return (NULL);
	if (!(str = (char*)malloc((len + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char		*join_and_free(char *str, char *buff)
{
	int		len1;
	int		len2;
	int		i;
	char	*dst;

	if (!str)
		return (ft_strdup(buff));
	if (!buff)
		return (NULL);
	len1 = ft_strlen(str);
	len2 = ft_strlen(buff);
	if (!(dst = (char*)malloc((len1 + len2 + 1) * sizeof(char))))
		return (NULL);
	i = -1;
	while (str[++i])
		dst[i] = str[i];
	free(str);
	str = NULL;
	i = -1;
	while (buff[++i])
		dst[len1 + i] = buff[i];
	dst[len1 + i] = '\0';
	return (dst);
}
