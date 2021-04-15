# include "../headers/overall.h"

void ft_echo(char *str, int flag_n)
{

	if (flag_n == 1)
	{
		write(0, str, ft_strlen(str));
		write(0, "\n", 1);
	}
	else
		write(0, str, ft_strlen(str));
}

