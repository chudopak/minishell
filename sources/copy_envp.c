#include "../headers/overall.h"

static int	count_variables(char **envp)
{
	int		i;

	i = 0;
	while (envp[i] != NULL)
		i++;
	return (i);
}

static char	*copy_variable(char *envp)
{
	int		str_len;
	int		i;
	char	*variable;

	str_len = ft_strlen(envp);
	variable = malloc(sizeof(char) * (str_len + 1));
	if (!variable)
		return (NULL);
	i = -1;
	while (++i < str_len)
		variable[i] = envp[i];
	variable[i] = '\0';
	return (variable);
}

void	copy_envp(t_all *all, char **envp)
{
	int		amount_of_variables;
	int		i;

	all->envp_copy = NULL;
	amount_of_variables = count_variables(envp);
	all->envp_copy = malloc(sizeof(char*) * (amount_of_variables + 1));
	if (!all->envp_copy)
		return ;
	all->envp_copy[amount_of_variables] = NULL;
	i = -1;
	while (++i < amount_of_variables)
	{
		all->envp_copy[i] = copy_variable(envp[i]);
		if (!all->envp_copy[i])
		{
			free_cmd(all->envp_copy);
			all->envp_copy = NULL;
			return ;
		}
	}
}