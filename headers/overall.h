#ifndef OVERALL_H
# define OVERALL_H

# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <signal.h>
# include <unistd.h>
# include <term.h>
# include "parser.h"
# include "../libft/libft.h"

typedef struct 	s_all
{
	char **env;
	char *arg;
}				t_all;

void	ft_pwd(void);
int		ft_echo(t_lst *list);

#endif
