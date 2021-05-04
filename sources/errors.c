#include "../headers/overall.h"

void	errors(t_all *all, int	error_code)
{
	all->writen_symblos = 0;
	exit(error_code);
}