#include "minishell.h"

int			assign_command(char *path, char **path_p, t_string *com, int i)
{
	if (path_p[i] != NULL)
	{
		clear(path_p);
		com->clear(com);
		*com = ft_string(path);
		free(path);
		return (0);
	}
	clear(path_p);
	return (-2);
}

int			check_command(t_shell *shell, t_string *command)
{
	char	*abs_path;
	char	**path_parsed;
	int		i;

	path_parsed = parse_path(shell);
	if (path_parsed == NULL)
		return (-2);
	if (ft_strchr(command->content, '/'))
	{
		clear(path_parsed);
		if (file_exists(command->content))
			return (0);
		return (-2);
	}
	i = 0;
	while (path_parsed[i])
	{
		abs_path = ft_strjoin(path_parsed[i], command->content);
		if (file_exists(abs_path))
			break ;
		free(abs_path);
		i++;
	}
	return (assign_command(abs_path, path_parsed, command, i));
}
