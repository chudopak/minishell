#include "../headers/overall.h"

void	free_command(t_command *command, t_all *all)
{
	if (command)
	{
		if (command->path != NULL)
			free(command->path);
//		free(command);
	}
	(void )all;
}
