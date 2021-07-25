#include "libft.h"

int	ft_putint(int c)
{
	return (write(1, &c, 1));
}
