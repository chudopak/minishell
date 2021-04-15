/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarash <pmarash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 17:55:33 by pmarash           #+#    #+#             */
/*   Updated: 2021/04/15 18:05:53 by pmarash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stdbool.h>

typedef struct s_lst{
	char			*str;
	struct s_lst	*next;
}					t_lst;

typedef struct s_status {
	bool			dbl_qt;
	bool			qt;
	int				pipe;
	int				semicolon;
}					t_status;

int		environment_to_struct(t_lst **env, char **envp);
t_lst	*lstnew_char(char *content);
void	lst_add_back(t_lst **lst, t_lst *new);
void	lstclear_char(t_lst **lst);
char	*char_join(char *arg, char symbol, int arg_size);
int		parser(char *data, t_lst **env);

#endif
