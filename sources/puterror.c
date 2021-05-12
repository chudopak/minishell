#include "../headers/overall.h"

int		puterror(char *msg, int error_code)
{
	if (!msg)
		msg = strerror(error_code);
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	g_errno = error_code;
	return (error_code);
}

int	puterror1(char *base_msg, char *token, char *s, int error_code)
{
	write(2, base_msg, ft_strlen(base_msg));
	write(2, token, ft_strlen(token));
	write(2, s, ft_strlen(s));
	write(2, "\n", 1);
	g_errno = error_code;
	return (error_code);
}
