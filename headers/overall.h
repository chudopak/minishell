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

int				g_errno;

typedef struct s_history
{
	char				cmd[1000];
}						t_history;

typedef struct	s_all
{
	t_lst			*env;
	t_history		*history;
	struct termios	term;
	struct termios	term_default_set;
	char			*term_name;
	int				cursor_pos;
	int				writen_symblos;

}				t_all;

int		ft_pwd(void);
int		ft_echo(t_lst *list);
void	handle_input(t_all *all);
int		unprint_symbols(char *str);
void	get_history_comand(t_all *all, char *str);
void	add_symbol(t_all *all, char *str, int ret, char *cmd);


#endif
