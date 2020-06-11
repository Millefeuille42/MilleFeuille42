#include "minishell.h"

static void			*safe_exit(char **commands, t_command *ret)
{
	int i;
	int i2;

	if (commands)
		ft_clear(commands);
	i = 0;
	while (ret && ret[i].end != 1)
	{
		ret[i].command.clear(&ret[i].command);
		i++;
		if (ret[i].argv)
			ft_clear(ret[i].argv);
	}
	if (ret)
		free(ret);
	ret = NULL;
	return (NULL);
}

t_command			*parse_command(char *line)
{
	int			i;
	t_command	*ret;
	char		**commands;

	commands = ft_parse(line, ';');
	free(line);
	if (!commands || !(ret = malloc(sizeof(t_command) * array_len(commands) + 1)))
		return (NULL);
	ret[array_len(commands)].end = 1;
	i = 0;
	while (commands[i])
	{
		ret[i].end = 0;
		if (!(ret[i].argv = ft_parse(commands[i], ' ')))
			return (safe_exit(commands, ret));
		if ((ret[i].command = ft_string(ret[i].argv[0])).size == 0)
			return (safe_exit(commands, ret));
	}
	ft_clear(commands);
	return (ret);
}