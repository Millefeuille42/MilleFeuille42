#include "minishell.h"

static void			*safe_exit(char **commands, t_command *ret)
{
	int i;

	if (commands)
		clear(commands);
	i = 0;
	while (ret && ret[i].end != 1)
	{
		ret[i].command.clear(&ret[i].command);
		i++;
		if (ret[i].argv)
			clear(ret[i].argv);
	}
	if (ret)
		free(ret);
	ret = NULL;
	return (NULL);
}

static char			*cut_wp(char *str)
{
	int		i;
	int		i2;
	char	*ret;

	i = 0;
	i2 = 0;
	while (str[i] && ft_cinset(str[i], "\n\r\t\v\f "))
		i++;
	if (!(ret = malloc(sizeof(char) * (ft_strlen(str) - i + 1))))
		return (NULL);
	while (str[i])
	{
		ret[i2] = str[i];
		i++;
		i2++;
	}
	ret[i2] = '\0';
	return (ret);
}

static char			**trim_array(char **array)
{
	char	*temp;
	int		i;

	i = 0;
	if (!array)
		return (NULL);
	while (array[i])
	{
		if (!(temp = cut_wp(array[i])))
			return (safe_exit(array, NULL));
		free(array[i]);
		array[i] = temp;
		i++;
	}
	return (array);
}

int					clean_command(t_command *commands)
{
	int i;
	int i2;

	i = 0;
	while (commands && !commands[i].end)
	{
		if (!commands[i].command.content[0])
			return ((int)safe_exit(NULL, commands) - 1);
		i2 = 0;
		while (commands[i].argv[i2] != NULL)
		{
			if (!commands[i].argv[i2][0])
			{
				if (!(commands[i].argv = ft_delete_entry(commands[i].argv, i2)))
					return ((int)safe_exit(NULL, commands) - 1);
				i2 = 0;
			}
			else
				i2++;
		}
		i++;
	}
	return (0);
}

t_command			*parse_command(char *line)
{
	int			i;
	t_command	*ret;
	char		**commands;

	commands = ft_parse(line, ';');
	commands = trim_array(commands);
	free(line);
	line = NULL;
	if (!commands || !(ret = malloc(sizeof(t_command)
			* (array_len(commands) + 1))))
		return (NULL);
	i = 0;
	ret[array_len(commands)].end = 1;
	while (commands[i])
	{
		ret[i].end = 0;
		if (!(ret[i].argv = ft_parse(commands[i], ' ')))
			return (safe_exit(commands, ret));
		if ((ret[i].command = ft_string(ret[i].argv[0])).size == 0)
			return (safe_exit(commands, ret));
		i++;
	}
	clear(commands);
	return (ret);
}
