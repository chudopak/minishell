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

/* ERROR code*/
# define ALL_OK 0
# define BAD_MALLOC 1
# define TERM_ERROR 2

/* History limit*/
# define HISTORY_LIMIT 999

int				g_errno;

typedef struct s_history
{
	char				*cmd;
	struct s_history	*next;
	struct s_history	*prev;
}						t_history;

typedef struct	s_all
{
	t_lst			*env;
	t_history		*current_cmd;
	t_history		*head_history;
	t_history		*stroller;
	struct termios	term;
	struct termios	term_default_set;
	char			*term_name;
	int				cursor_pos;
	int				writen_symblos;
	int				cmd_in_history;
}				t_all;

int		parser(char *data, t_all *all);
int		ft_pwd(void);
int		ft_echo(t_lst *list);
void	handle_input(t_all *all);
int		unprint_symbols(char *str);
void	get_history_comand(t_all *all, char *str);
void	add_symbol(t_all *all, char *str, int ret, char *cmd);
void	errors(t_all *all, int	error_code);
void	rm_node(t_all *all);




#endif
