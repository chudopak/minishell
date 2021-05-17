/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarash <pmarash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 17:40:08 by pmarash           #+#    #+#             */
/*   Updated: 2020/11/21 17:40:52 by pmarash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

int			get_next_line(int fd, char **line);
char		*join_and_free(char *s1, char *s2);
char		*ft_substr(char const *s, int start, int len);
void		*ft_memmove(void *dst, const void *src, size_t len);
char		*ft_strdup(const char *s1);
size_t		ft_strlen(const char *s);

#endif
