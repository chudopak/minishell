#ifndef OVERALL_H
# define OVERALL_H

# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <signal.h>
# include <unistd.h>
# include <term.h>
# include <sys/ioctl.h>
# include <string.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include "parser.h"
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"

/* ERROR code*/
# define ALL_OK 0
# define BAD_MALLOC 1
# define TERM_ERROR 2
# define ENV_ERROR 3
# define PATH_MISSING 4

/* History limit*/
# define HISTORY_LIMIT 10

int				g_errno;

typedef struct s_history
{
	char				*cmd;
	struct s_history	*next;
	struct s_history	*prev;
}						t_history;

typedef struct	s_command
{
	char		**cmd;
	int			pipein;
	int			pipeout;
	int			redirectin;
	int			redirectout;
}				t_command;

typedef struct	s_all
{
	t_env_list		*env;
	t_history		*current_cmd;
	t_history		*head_history;
	t_history		*stroller;
	struct termios	term;
	struct termios	term_default_set;
	struct winsize 	win;
	char			*term_name;
	char			*path;
	int 			fd[2];
	int 			stdout_tmp;
	int 			stdin_tmp;
	char			**envp_copy;
	int				cursor_pos;
	int				writen_symblos;
	int				cmd_in_history;
	int				pipein;
	int				redirect;
}				t_all;

int			parser(char *data, /*t_lst **env*/ t_all *all);
void		handle_input(t_all *all);
void		get_history_comand(t_all *all, char *str);
void		add_symbol(t_all *all, char *str, int ret, char *cmd);
void		handle_ctrl_c(t_all *all);
void		manage_backspace(t_all *all);
char		*delete_symbol(t_all *all);
int			handle_arrows(t_all *all, char **data, t_lst **last_arg);
int			set_to_exec(t_all *all, t_lst **args, t_lst **last_arg, char **data);
void		copy_envp(t_all *all, char **envp);
void		set_path(t_env_list *env, char **path);
/*
** history
*/
void		new_history_elem(t_all *all);
void		set_history(t_all *all);
void		push_writen_in_history(t_all *all);
void		set_head_of_history(t_all *all);

/*
** Built_in
*/

void		ft_exit(char **args);
void		ft_env(t_all *all);
void		ft_unset(t_all *all, char **args);
void		ft_cd(t_all *all, char *new_path);
void		ft_echo(char **args);
void		ft_pwd(void);
void		ft_export(char **args, t_all *all);

/*
** Logic
*/

void		distribution_to_exec(t_all *all, t_command *command);
void		open_pipes(t_all *all, t_command *command);
void		open_redirect(t_all *all, t_command *command);
void		close_redirect(t_all *all, t_command *command);
void		check_right_pipe(t_all *all, t_command *command);
void		check_left_pipe(t_all *all, t_command *command);

/*
** Utils1
*/
void		rm_node(t_all *all);
int			unprint_symbols(char *str);
void		remove_elem_history(t_all *all);
int			is_separator(char c);
int			is_correct_str(const char *str);
int			find_name_len(const char *str);
int			set_id(const char *envp_str);
void		free_map(char **map);
char		**env_to_charpp(t_all *all);
int			ft_env_list_size(t_env_list *lst);
void		ft_env_list_print(t_env_list *env_list);
void		ft_env_list_print_with_declare(t_env_list *env_list);
int			ft_env_list_remove(t_env_list **list, char *key);
void		ft_env_list_replace(t_env_list *list, t_env_item *new_item);
t_env_list	*ft_env_list_new(t_env_item *env_item);
int			ft_env_list_len(t_env_list *env_list);
char		*ft_env_list_get_value(t_env_list *env_list, char *key);
t_env_list	*ft_env_list_copy(t_env_list *list);
void		ft_env_item_free(t_env_item *item);
t_env_item	*ft_env_item_new(char *key, int id, char *value);
void		ft_env_list_add_back(t_env_list **env_list, t_env_list *new);
void		ft_env_item_del(t_env_item *item);
void		ft_env_list_clear(t_env_list **lst);
int			ft_env_key_exist(t_env_list *list, char *key);
t_env_item	*ft_get_env_item_with_key(t_env_list *list, char *key);
t_env_item	*get_env_item_from_envp_string(const char *envp_string);
char		*split_path(t_all *all, t_command *command);

/*
** Error's managment
*/
int			puterror(char *msg, int error_code);
int			puterror1(char *base_msg, char *token, char *s, int error_code);
int			puterror2(char *base_msg, char *token, int error_code);
void		errors(char *error_msg, int error_code);
int			invalid_pipe_semicolom_token(char *data);
int			syntax_error_checker(char *data);

/*
** set_to_exec functions
*/
void		clear_leftover(t_command *command, t_lst **args);
int			check_last_arg_for_null(t_lst *last_arg);
t_command	set_token(t_all *all, char symbol);
void		set_token_pipes(t_all *all, t_command *command, char symbol);
int			set_fd(t_command *command, char *redir_type, char *file_name);
int			set_fd_for_redirect(t_lst *args, t_command *command);

/*
** parser for better understanding what function doing
*/
void		prepare_to_exec(t_all *all, t_lst **args,
							t_lst **last_arg, char **data);
void		handle_space_arrow(t_all *all, char **data,
							t_lst **last_arg, int *arg_size);
void		handle_special_symbol(t_all *all, char **arg,
							char **data, int *arg_size);
void		add_usual_symbol(t_lst **last_arg,
							char **data, int *arg_size);

/*
** utils for interact with env structure
*/
t_env_item	*new_env_item(char *key, int id, char *value);
t_env_list	*new_env_list(t_env_item *env_item);
void		env_list_add_back(t_env_list **env_list, t_env_list *new);
void		free_env_item(t_env_item *item);

#endif
