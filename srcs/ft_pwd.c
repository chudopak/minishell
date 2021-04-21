#include "../headers/overall.h"

void ft_pwd(void)
{
	char str[100];

	getcwd(str, 100);
	printf("Current dir is %s\n", str);
}
