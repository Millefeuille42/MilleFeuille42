#include "minishell.h"

void	ft_replace_env(t_shell *shell, char *key, char *value)
{
	if (shell->env_get(shell, key))
		shell->env_remove(shell, key);
	shell->add_env(shell, key, value);
}
