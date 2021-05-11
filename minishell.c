#include "./headers/overall.h"

static void set_history(t_all *all)
{
	t_history	*tmp;

	tmp = malloc(sizeof(t_history));
	if (!tmp)
		errors(all, BAD_MALLOC);
	tmp->next = NULL;
	tmp->cmd = NULL;
	tmp->prev = NULL;
	all->head_history = tmp;
	all->current_cmd = tmp;
}

static void	set_all(t_all *all, char **envp)
{
	g_errno = 0;
	all->head_history = NULL;
	all->pipein = 0;
	all->redirectout = 0;
	all->redirectin = 0;
	all->redirect = 0;
	all->current_cmd = NULL;
	all->stroller = NULL;
	all->cursor_pos = 0;
	all->writen_symblos = 0;
	all->cmd_in_history = 0;
	all->env = NULL;
	ioctl(1, TIOCGWINSZ, &all->win);
	set_history(all);
	environment_to_struct(&(all->env), envp);
	all->term_name = "xterm-256color";
	if (!all->env)
		errors(all, ENV_ERROR);
	if (tcgetattr(0, &(all->term)))
		errors(all, TERM_ERROR);																//error managment
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
