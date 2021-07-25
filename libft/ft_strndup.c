#include "libft.h"

char	*ft_strndup(const char *s1, int n)
{
	char	*res;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen((char *)s1);
	res = malloc(sizeof(char) * (len + 1));
	if (!res || !s1)
		return (NULL);
	while (s1[i] && i < n)
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
