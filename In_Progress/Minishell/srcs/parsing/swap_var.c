#include "minishell.h"

char	*swap_var(t_shell *shell, char *str)
{
	char *temp;

	temp = shell->env_get(shell, str + 1);
	free(str);
	str = temp;
	if (!temp)
		str = ft_strdup("");
	return (str);
}