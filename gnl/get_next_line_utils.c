#include "../headers/overall.h"

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

//char	*ft_substr(char const *s, unsigned int start, size_t len)
//{
//	char			*sub;
//	unsigned int	i;
//
//	if (!s)
//		return (NULL);
//	i = 0;
//	if (ft_strlen(s) < start)
//	{
//		sub = (char *)malloc(sizeof(char));
//		sub[i] = '\0';
//		return (sub);
//	}
//	if (ft_strlen(s) < len)
//		len = ft_strlen(s);
//	sub = (char *)malloc(sizeof(char) * (len + 1));
//	if (!sub)
//		return (NULL);
//	while (i < len && s[start])
//		sub[i++] = s[start++];
//	sub[i] = '\0';
//	return (sub);
//}
