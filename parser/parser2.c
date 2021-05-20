#include "../headers/overall.h"

void	prepare_to_exec(t_all *all, t_lst **args,
							t_lst **last_arg, char **data)
{
	if ((*last_arg)->str == NULL)
		put_endline(last_arg);
	set_to_exec(all, args, last_arg, data);
}

void	handle_space_arrow(t_all *all, char **data,
							t_lst **last_arg, int *arg_size)
{
	int		status;

	if (**data == '>' || **data == '<')
	{
		status = handle_arrows(all, data, last_arg);
		if (status)
			errors("Error: malloc error in \"handle_arrows\".\n", BAD_MALLOC);
		*arg_size = -1;
	}
	else if (**data == ' ')
	{
		if (handle_space(data, last_arg) == 1)
			errors("Error: malloc error in \"handle_space\".\n", BAD_MALLOC);
		*arg_size = -1;
	}
}

void	handle_special_symbol(t_all *all, char **arg,
								char **data, int *arg_size)
{
	if (special_symbol(arg, data, arg_size, &all->env))
		errors("Error: malloc error in \"special_symbol\".\n", BAD_MALLOC);
}

void	add_usual_symbol(t_lst **last_arg,
							char **data, int *arg_size)
{
	(*last_arg)->str = char_join(&(*last_arg)->str, **data, *arg_size);
	if (!(*last_arg)->str)
		errors("Error: malloc error in \"add_usual_symbol\".\n", BAD_MALLOC);
}
