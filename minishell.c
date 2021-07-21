#include "./headers/overall.h"

static void	set_all(t_all *all, char **envp)
{
	g_errno = 0;
	all->pipein = 0;
	all->redirect = 0;
	all->current_cmd = NULL;
	all->stroller = NULL;
	all->cursor_pos = 0;
	all->writen_symblos = 0;
	all->cmd_in_history = 0;
	all->env = NULL;
	//signal(SIGINT, handle_signals);
	//signal(SIGQUIT, handle_signals);
	ioctl(1, TIOCGWINSZ, &all->win);
	set_history(all);
	environment_to_struct(&(all->env), envp);
	//while (all->env)
	//{
	//	printf("ENVP - %s\n", *envp);
	//	printf("id - %d\n", all->env->item->id);
	//	printf("key - %s\n", all->env->item->key);
	//	printf("value - %s\n", all->env->item->value);
	//	printf("------------------------------\n");
	//	all->env = all->env->next;
	//	envp++;
	//}
	//while (1);
	if (!all->env)
		errors("Error: can't load evironment.\n", ENV_ERROR);
	all->term_name = "xterm-256color";
	if (tcgetattr(0, &(all->term)))
		errors("Error: can't get terminal attrebuts.\n", TERM_ERROR);																//error managment
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
