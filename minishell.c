#include "./headers/overall.h"

static void	set_all(t_all *all, char **envp)
{
	g_errno = 0;
	all->cursor_pos = 0;
	all->writen_symblos = 0;
	all->env = NULL;
	environment_to_struct(&(all->env), envp);
	all->term_name = "xterm-256color";
	if (tcgetattr(0, &(all->term)))
		return ;																//error managment
	tgetent(0, all->term_name);
	all->cursor_pos = 0;
}

int		main(int ac, char **av, char **envp)
{
	t_all	all;

	if (ac && av)
		;
	set_all(&all, envp);
	while (1)
	{
		all.term.c_lflag &= ~(ECHO);
		all.term.c_lflag &= ~(ICANON);
		all.term.c_lflag &= ~(ISIG);
		tcsetattr(0, TCSANOW, &all.term);
		tputs(save_cursor, 1, ft_putint);
		handle_input(&all);
	}
	return (0);
}
