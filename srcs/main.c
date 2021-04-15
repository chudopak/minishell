#include "../headers/overall.h"

int main(void)
{
	char	str[2000];
	int 	x;

	x = read(0, str, 100);
	write(1, str, x);
	ft_pwd();
	return (0);
}