#include "../headers/overall.h"

void ft_pwd(void)
{
	char *buf;

	buf = getcwd(NULL, 0);
	g_errno = errno;
	if (buf)
		g_errno = 0;
	else
		ft_putstr_fd(strerror(g_errno), 2);
	ft_putstr_fd(buf, 1);
	write(1, "\n", 1);
	free(buf);
}