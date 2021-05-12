#ifndef PARSER_H
# define PARSER_H

# include <stdbool.h>

/*#define DOUBLE_QUOTES (1 << 0) // 1
#define QOUTES (1 << 1) // 2
#define PIPE (1 << 2) // 4
#define FLAG_3 (1 << 3) // 8
#define FLAG_4 (1 << 4) // 16
#define FLAG_5 (1 << 5) // 32
#define FLAG_6 (1 << 6) // 64
#define FLAG_7 (1 << 7) // 128*/

typedef struct s_lst{
	char			*str;
	struct s_lst	*next;
}					t_lst;

typedef struct s_redirect {
	int				right;
	int				left;
}					t_redirect;

/*typedef struct s_status {
	bool		double_quotes;
	bool		quotes;
	int			pipe;
	int			semicolon;
}				t_status;*/

void	environment_to_struct(t_lst **env, char **envp);
t_lst	*lstnew_char(char *content);
void	lst_add_back(t_lst **lst, t_lst *new);
void	lstclear_char(t_lst **lst);
int		lst_size(t_lst *lst);
void	lst_clear(t_lst *lst);
void	lst_delone(t_lst *lst);
char	*char_join(char **arg, char symbol, int arg_size);
int		special_symbol(char **arg, char **data, int *arg_size, t_lst **env);
int		double_quotes(char **arg, char **data, int *arg_size, t_lst **env);
int		dollar(char **arg, char **data, int *arg_size, t_lst **env);
int		get_env_ergument(char **arg, char **data, int *arg_size, t_lst **env);
void	skip_unnecessary_symbols(char **data, t_lst *tmp);
int		add_matched_argument(char **arg, char *env_arg, int *arg_size);
int		backslash_double_quotes(char **arg, char **data, int *arg_size);
int		cmp_data_to_env(char *s1, char *s2);
int		back_slash(char **arg, char **data, int *arg_size);
int		single_quotes(char **arg, char **data, int *arg_size);
int		handle_space(char **data, t_lst **last_arg);
int		put_endline(t_lst **last_arg);
int		add_g_errno(char **arg, char **data, int *arg_size);
void	free_cmd(char **cmd);

#endif
