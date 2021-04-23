# include "../headers/overall.h"

int args_size(char **args)
{
	int size;

	size = 0;
	while (args[size])
		size++;
	return (size);
}

int ft_echo(t_lst *list)
{
	int i;
	int flag_n;
	char **args;

	i = 0;
	while (list->next)
	{
		args[i] = (char *)malloc(ft_strlen(list->str) + 1);
		if (!args[i])
			return (-1);
		args[i] = list->str;
		args[i][ft_strlen(list->str)] = '\0';
		list = list->next;
	}
	flag_n = 0;
	i = 0;
	if (args_size(args) > 1)
	{
		while (args[i] && ft_strncmp(args[i], "-n", ft_strlen(args[i])))
		{
			flag_n = 1;
			i++;
		}
		while (args[i])
		{
			ft_putstr_fd(args[i], 1);
			if (args[1 + i] && args[i][0] != '\0')
				write(1, " ", 1);
		}
	}
	if (flag_n == 0)
		write(1, "\n", 1);
	return (0);
}

