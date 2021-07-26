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
