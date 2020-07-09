#include "minishell.h"
#include "parsing.h"

static int	parse_commands(t_shell *shell, char ***command, t_command **parsed)
{
	char	*input;
	int		err;
	int		len;

	input = "";
	err = ft_read_input(shell, NULL, &input);
	if (err)
		return (err);
	if (!input)
		return (ERREMPTY);
	err = get_n(input, get_next_command, command);
	free(input);
	if (err)
		return (err);
	len = ft_len(*command);
	if (!(*parsed = malloc(sizeof(t_command) * (len + 1))))
	{
		clear(*command);
		return (ERRMALLOC);
	}
	(*parsed)[len].end = 1;
	return (0);
}

int			parse(t_shell *shell, t_command **parsed)
{
	char	**command;
	char	**command_parsed;
	int		err;
	int		i;

	err = parse_commands(shell, &command, parsed);
	if (err)
		return (err);
	i = 0;
	while (command[i])
	{
		err = get_n(command[i], get_next_arg, &command_parsed);
		if (err)
			break ;
		(*parsed)[i].argv = command_parsed;
		(*parsed)[i].command = ft_strdup(command_parsed[0]);
		(*parsed)[i].end = 0;
		i++;
	}
	clear(command);
	return (err);
}
