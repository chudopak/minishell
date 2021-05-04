#include "../headers/overall.h"

void	environment_to_struct(t_lst **env, char **envp)
{
	t_lst	*tmp;

	while (*envp)
	{
		tmp = lstnew_char(*envp);
		if (!tmp)
		{
			lstclear_char(env);
			return ;										//error managment
		}
		lst_add_back(env, tmp);
		envp++;
	}
}
