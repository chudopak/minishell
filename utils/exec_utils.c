#include "../headers/overall.h"

void	free_command(t_command *command, t_all *all)
{
	if (command)
	{
		if (command->path)
			free(command->path);
		if (command->cmd)
			free_map(command->cmd);
	}
	if (all->envp_copy)
		free_map(all->envp_copy);
}