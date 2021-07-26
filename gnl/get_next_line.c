/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarash <pmarash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 11:46:05 by pmarash           #+#    #+#             */
/*   Updated: 2021/07/26 16:51:54 by pmarash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include "get_next_line.h"

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
*/

#include "get_next_line.h"

static int	check_line(char *ostatok, char **line, char *buf)
{
	int		i;
	size_t	len;

	i = 0;
	if (!ostatok)
		return (0);
	while (ostatok [i] != '\n')
		if (!ostatok[i++])
			return (0);
	free (buf);
	*line = ft_substr(ostatok, 0, i);
	i++;
	len = ft_strlen(ostatok + i) + 1;
	ostatok = ft_memmove(ostatok, ostatok + i, len);
	return (1);
}

static int	error_case(char *buf)
{
	if (buf)
		free(buf);
	return (-1);
}

static char	*join_from_buf(char *ostatok, char *buf)
{
	char	*res;
	int		i;
	int		len1;

	i = 0;
	if (!ostatok)
		return (ft_strdup(buf));
	if (!buf)
		return (NULL);
	len1 = ft_strlen(ostatok);
	res = (char *)malloc(sizeof(char) * (len1 + ft_strlen(buf) + 1));
	if (!res)
		return (NULL);
	while (ostatok[i])
	{
		res[i] = ostatok[i];
		i++;
	}
	free (ostatok);
	i = -1;
	while (buf[++i])
		res[len1 + i] = buf[i];
	res[len1 + i] = '\0';
	return (res);
}

static int	i_love_norms(char **ostatok, char **buf, char **line, int n_read)
{
	*(*buf + n_read) = '\0';
	*ostatok = join_from_buf(*ostatok, *buf);
	if (*ostatok && check_line(*ostatok, line, *buf))
		return (1);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	char		*buf;
	static char	*ostatok;
	int			i;
	size_t		n_read;

	i = 0;
	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf || read(fd, buf, 0) < 0)
		return (error_case(buf));
	if (ostatok)
		if (check_line(ostatok, line, buf))
			return (1);
	while (1)
	{
		n_read = read(fd, buf, BUFFER_SIZE);
		if (n_read <= 0)
			break ;
		if (i_love_norms(&ostatok, &buf, line, n_read) > 0)
			return (1);
	}
	end_case(&buf, &ostatok, line);
	return (0);
}