#include "../headers/overall.h"

int	set_fd(t_command *command, char *redir_type, char *file_name)
{
	if (!ft_strcmp(redir_type, ">>"))
	{
		if (command->redirectout != -1)
			close(command->redirectout);
		command->redirectout = open(file_name,
				O_WRONLY | O_APPEND | O_CREAT, S_IRWXU);
		if (command->redirectout == -1)
			return (puterror1(file_name, ": ", strerror(errno), errno));
	}
	else if (!ft_strcmp(redir_type, ">"))
	{
		if (command->redirectout != -1)
			close(command->redirectout);
		command->redirectout = open(file_name,
				O_WRONLY | O_TRUNC | O_CREAT, S_IRWXU);
		if (command->redirectout == -1)
			return (puterror1(file_name, ": ", strerror(errno), errno));
	}
	else if (!ft_strcmp(redir_type, "<"))
	{
		if (command->redirectin != -1)
			close(command->redirectin);
		command->redirectin = open(file_name, O_RDONLY, S_IRWXU);
		if (command->redirectin == -1)
			return (puterror1(file_name, ": ", strerror(errno), errno));
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


//int	set_fd_for_redirect(t_command *command)
//{
//	int		i;
//	int		status;
//
//	i = 0;
//	while (command->cmd[i])
//	{
//		if (!ft_strcmp(command->cmd[i], ">>")
//			|| !ft_strcmp(command->cmd[i], ">")
//			|| !ft_strcmp(command->cmd[i], "<"))
//		{
//			status = set_fd(command, command->cmd[i], *(command->cmd + i + 1));
//			if (status)
//				return (-1);
//			i++;
//		}
//		i++;
//	}
//	return (0);
//}
//