#include "../headers/overall.h"

static void	set_for_parsing(t_lst **args, t_lst **last_arg,
							int *arg_size, char **data)
{
	*args = lstnew_char(NULL);
	*last_arg = *args;
	*arg_size = 0;
	while (**data == ' ' && **data)
		(*data)++;
}

int	parser(char *data, t_all *all)
{
	t_lst	*args;
	t_lst	*last_arg;
	int		arg_size;

	if (!data || !*data)
		return (ALL_OK);
	set_for_parsing(&args, &last_arg, &arg_size, &data);
	while (!ft_strchr("\n\0#", *data))
	{
		if (*data == '|' || *data == ';')
			arg_size = set_to_exec(all, &args, &last_arg, &data);
		if (*data == '\"' || *data == '\'' || *data == '$' || *data == '\\')
			handle_special_symbol(all, &(last_arg->str), &data, &arg_size);
		else if (*data == '>' || *data == '<' || *data == ' ')
			handle_space_arrow(all, &data, &last_arg, &arg_size);
		else
			add_usual_symbol(&last_arg, &data, &arg_size);
		data++;
		arg_size++;
	}
	prepare_to_exec(all, &args, &last_arg, &data);
	return (ALL_OK);
}
