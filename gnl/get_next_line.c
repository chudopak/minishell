/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarash <pmarash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 11:46:05 by pmarash           #+#    #+#             */
/*   Updated: 2021/07/25 19:36:59 by vping            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	search_index(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i] && s[i] != (char)c)
		i++;
	if (s[i] != (char)c)
		return (-1);
	return (i);
}

static int	get_line(char *str, char **line, int i)
{
	int		len;

	*line = ft_substr(str, 0, i);
	++i;
	len = ft_strlen(str + i) + 1;
	ft_memmove(str, str + i, len);
	return (1);
}

static void	thks_norm(char **line, char **str, char **buff)
{
	if (*str)
	{
		*line = ft_strdup(*str);
		free(*str);
		*str = NULL;
	}
	else
		*line = ft_strdup("");
	free(*buff);
}

int	get_next_line(int fd, char **line)
{
	char		*buff;
	static char	*str;
	int			buf_size;
	int			i;

	buff = malloc(BUFFER_SIZE + 1);
	if (fd < 0 || !line || BUFFER_SIZE < 1
		|| !(buff = malloc(BUFFER_SIZE + 1)) || read(fd, buff, 0) < 0)
		return (-1);
	if (str && (((i = search_index(str, '\n')) != -1)))
	{
		free(buff);
		return (get_line(str, line, i));
	}
	while ((buf_size = read(fd, buff, BUFFER_SIZE)))
	{
		buff[buf_size] = '\0';
		str = join_and_free(str, buff);
		if (((i = search_index(str, '\n')) != -1))
		{
			free(buff);
			return (get_line(str, line, i));
		}
	}
	thks_norm(line, &str, &buff);
	return (buf_size);
}
