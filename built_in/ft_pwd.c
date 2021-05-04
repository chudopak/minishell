#include "../headers/overall.h"

int ft_pwd(void)
{
	char str[100];

	if (getcwd(str, 100))
	{
		ft_putendl_fd(str, 1);
		return (1);
	}
	else
		return (0);
}
