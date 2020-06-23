#include "minishell.h"

int			assign_command(char *path, char **path_p, char **com, int i)
{
	if (path_p[i] != NULL)
	{
		clear(path_p);
		free(*com);
		*com = ft_strdup(path);
		free(path);
		return (0);
	}
	clear(path_p);
	return (-2);
}

int			check_command(t_shell *shell, char **command)
{
	char	*abs_path;
	char	**path_parsed;
	int		i;

	path_parsed = parse_path(shell);
	if (path_parsed == NULL)
		return (-2);
	if (ft_strchr(*command, '/'))
	{
		clear(path_parsed);
		if (file_exists(*command))
			return (0);
		return (-2);
	}
	i = 0;
	while (path_parsed[i])
	{
		abs_path = ft_strjoin(path_parsed[i], *command);
		if (file_exists(abs_path))
			break ;
		free(abs_path);
		i++;
	}
	return (assign_command(abs_path, path_parsed, command, i));
}
