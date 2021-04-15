/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarash <pmarash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 18:56:02 by pmarash           #+#    #+#             */
/*   Updated: 2021/04/15 18:33:56 by pmarash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/overall.h"

static int	handle_space(char **data, t_lst **last_arg)
{
	t_lst	*tmp;

	tmp = lstnew_char(NULL);
	if (!tmp)
		return (1);
	lst_add_back(last_arg, tmp);
	*last_arg = (*last_arg)->next;
	while (**data == ' ')
		(*data)++;
	return (0);
}

static void test_parsed(t_lst *args)
{
	while (args->next)
	{
		printf("%s\n", args->str);
		args = args->next;
	}
	printf("%s\n", args->str);
}

int	parser(char *data, t_lst **env)
{
	t_lst	*args;
	t_lst	*last_arg;
	char	*tmp;
	int		arg_size;												// length of current argument

	if (!*data || !data)
		return (0);
	args = lstnew_char(NULL);
	last_arg = args;
	arg_size = 0;													//check how u gonna count size couse of char join
	while (*data)
	{
		if (*data == '\"' || *data == '\'' || *data == ';'			//
			|| *data == '|' || *data == '$')						//
			return (1);												// write function here 
		else if (*data == ' ')
		{
			if (handle_space(&data, &last_arg) == 1)				//and don't forget about this
				return (1);											// ERROR retrun (Malloc)
			arg_size = 0;
			continue ;
		}
		else
		{
			tmp = last_arg->str;
			free(last_arg->str);
			last_arg->str = char_join(tmp, *data, arg_size);
			if (!last_arg->str)
				return (1);											//error return (malloc)
		}
		data++;
		arg_size++;
	}
	test_parsed(args);
	printf("\n\n");
	lstclear_char(&args);
	*((*env)->str) = '0';
	return (0);
}
