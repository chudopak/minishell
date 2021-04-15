#include "../headers/overall.h"

void	web(char *str)
{
	//if (!(ft_strncmp(str, "echo", 4)))
		ft_echo(str, 0);
	if (!(ft_strncmp(str, "pwd", 3)))
		ft_pwd();
	else
	{
		write(1, "command not found: ", 21);
		write(1, str, ft_strlen(str));
	}
}

int		main(void)
{
	char	str[2000];
	int 	x;

	x = read(0, str, 100);
	web(str);
	return (0);
}