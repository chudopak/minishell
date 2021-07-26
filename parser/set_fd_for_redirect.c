#include "../headers/overall.h"

int	set_fd(t_command *com, char *redir_type, char *f_name)
{
	if (!ft_strcmp(redir_type, ">>"))
	{
		if (com->redirectout != -1)
			close(com->redirectout);
		com->redirectout = open(f_name, O_WRONLY | O_APPEND | O_CREAT, S_IRWXU);
		if (com->redirectout == -1)
			return (puterror1(f_name, ": ", strerror(errno), errno));
	}
	else if (!ft_strcmp(redir_type, ">"))
	{
		if (com->redirectout != -1)
			close(com->redirectout);
		com->redirectout = open(f_name, O_WRONLY | O_TRUNC | O_CREAT, S_IRWXU);
		if (com->redirectout == -1)
			return (puterror1(f_name, ": ", strerror(errno), errno));
	}
	else if (!ft_strcmp(redir_type, "<"))
	{
		if (com->redirectin != -1)
			close(com->redirectin);
		com->redirectin = open(f_name, O_RDONLY, S_IRWXU);
		if (com->redirectin == -1)
			return (puterror1(f_name, ": ", strerror(errno), errno));
	}
	return (0);
}

int	set_fd_for_redirect(t_lst *args, t_command *command)
{
	int		status;

	while (args)
	{
		if (!ft_strcmp(args->str, ">>")
			|| !ft_strcmp(args->str, ">")
			|| !ft_strcmp(args->str, "<"))
		{
			status = set_fd(command, args->str, (args->next)->str);
			if (status)
				return (-1);
			args = args->next;
		}
		args = args->next;
	}
	return (0);
}
