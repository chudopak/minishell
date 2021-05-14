#include "../headers/overall.h"

void	errors(char *exit_massage, int	error_code)
{
	ft_putstr_fd(exit_massage, 1);
	exit(error_code);
}