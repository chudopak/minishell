#include "../headers/overall.h"

int	environment_to_struct(t_lst **env, char **envp)
{
	t_lst	*tmp;

	while (*envp)
	{
		tmp = lstnew_char(*envp);
		if (!tmp)
		{
			lstclear_char(env);
			return (1);
		}
		lst_add_back(env, tmp);
		envp++;
	}
	return (0);
}
