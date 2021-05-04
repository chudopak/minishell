#include "../headers/overall.h"

void	add_symbol(t_all *all, char *str, int ret, char *cmd)
{
	int	i;

	i = -1;
	while (all->writen_symblos < ret)
	{
		cmd[i] = str[i];
		all->writen_symblos++;
	}
	write(1, str, ret);
	all->cursor_pos += ret;
}

void	get_history_comand(t_all *all, char *str)
{
	t_all tmp;

	tmp = *all;
	if (!ft_strcmp(str, "\e[B"))
		write(1, "UP", 2);													//don't forget
	else
		write(1, "DOWN", 4);												//don't forget
}

int	unprint_symbols(char *str)
{
	if (*str < 32 && (*str != '\n' && *str != 3 && *str != 4))
		return (1);
	return (0);
}

void	handle_input(t_all *all)
{
	char	str[50];
	int		readed;
	char	cmd[1000];

	while (1)
	{
		readed = read(0, str, 100);
		str[readed] = '\0';
		if (!ft_strcmp(str, "\e[A") || !ft_strcmp(str, "\e[B"))
			get_history_comand(all, str);
		else if (!ft_strcmp(str, "\3"))
			write(1, "ctrl_c", ft_strlen("ctrl_c"));						//don't forget
		else if (!ft_strcmp(str, "\4"))
			exit(g_errno);													//don't forget ctrl d
		//else if (!ft_strcmp(str, "\177") || *str == '\b')
		//	backspase();
		else if (unprint_symbols(str))
			continue ;
		else if (ft_strcmp(str, "\n"))
			add_symbol(all, str, readed, cmd);
		else
			break ;
	}
	cmd[all->writen_symblos] = '\0';
	all->writen_symblos = 0;
	parser(cmd, &(all->env));
}
