/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarash <pmarash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 11:46:25 by pmarash           #+#    #+#             */
/*   Updated: 2021/07/26 16:52:23 by pmarash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include "get_next_line.h"

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

	if (!s1)
		return (NULL);
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
*/
#include "get_next_line.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*d;
	char	*s;

	i = 0;
	d = (char *)dst;
	s = (char *)src;
	if (!dst && !src)
		return (NULL);
	if (d > s)
	{
		while (len-- > 0)
			d[len] = s[len];
	}
	else
	{
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (d);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *str)
{
	unsigned int	i;
	char			*copy;

	i = 0;
	if (!str)
		return (NULL);
	copy = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!copy)
		return (NULL);
	while (str[i])
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

void	end_case(char **buf, char **ostatok, char **line)
{
	if (*ostatok)
	{
		*line = ft_strdup(*ostatok);
		free(*ostatok);
		*ostatok = NULL;
	}
	else
		*line = ft_strdup("");
	free(*buf);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;

	if (!s)
		return (NULL);
	i = 0;
	if (ft_strlen(s) < start)
	{
		sub = (char *)malloc(sizeof(char));
		sub[i] = '\0';
		return (sub);
	}
	if (ft_strlen(s) < len)
		len = ft_strlen(s);
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	while (i < len && s[start])
		sub[i++] = s[start++];
	sub[i] = '\0';
	return (sub);
}