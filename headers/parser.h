/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarash <pmarash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 17:55:33 by pmarash           #+#    #+#             */
/*   Updated: 2021/04/20 16:26:45 by pmarash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stdbool.h>

# define ALL_OK 0
# define BAD_MALLOC 1
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

/*typedef struct s_status {
	bool		double_quotes;
	bool		quotes;
	int			pipe;
	int			semicolon;
}				t_status;*/

int		environment_to_struct(t_lst **env, char **envp);
t_lst	*lstnew_char(char *content);
void	lst_add_back(t_lst **lst, t_lst *new);
void	lstclear_char(t_lst **lst);
char	*char_join(char **arg, char symbol, int arg_size);
int		parser(char *data, t_lst **env);
int		special_symbol(char **arg, char **data, int *arg_size, t_lst **env);
int		double_quotes(char **arg, char **data, int *arg_size, t_lst **env);
int		dollar(char **arg, char **data, int *arg_size, t_lst **env);
int		get_env_ergument(char **arg, char **data, int *arg_size, t_lst **env);
void	skip_unnecessary_symbols(char **data, t_lst *tmp);
int		add_matched_argument(char **arg, char *env_arg, int *arg_size);
int		backslash_double_quotes(char **arg, char **data, int *arg_size);
int		cmp_data_to_env(char *s1, char *s2);
int		single_quotes(char **arg, char **data, int *arg_size);


#endif
