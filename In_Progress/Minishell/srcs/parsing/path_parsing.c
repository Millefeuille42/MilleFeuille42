#include "minishell.h"

char	**parse_path(t_shell *shell)
{
	char	*env;
	char	**path_parsed;
	int		i;

	if (!(env = shell->env_get(shell, "PATH")))
		return (NULL);
	path_parsed = ft_parse(env, ':');
	i = 0;
	while (path_parsed[i])
	{
		if (path_parsed[i][ft_strlen(path_parsed[i]) - 1] != '/')
		{
			env = ft_strjoin(path_parsed[i], "/");
			free(path_parsed[i]);
			path_parsed[i] = env;
		}
		i++;
	}
	return (path_parsed);
}
