#include "../headers/overall.h"

void	free_command(t_command *command, t_all *all)
{
	if (command)
		if (command->path != NULL)
			free(command->path);
	if (all->envp_copy != NULL)
		free_map(all->envp_copy);
	free(command);
}
