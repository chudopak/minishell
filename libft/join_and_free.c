#include "libft.h"

char	*join_and_free(char *str, char *buff)
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
	dst = malloc((len1 + len2 + 1) * sizeof(char));
	if (!dst)
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
