#include "minishell.h"

typedef struct	s_command
{
	char		*command;
	char		*argv[];
}				t_command;

char	**parse_line(char *line)
{
	char	**line_parsed;

	line_parsed = ft_parse(line, ';');
	free(line);
	return (line_parsed);
}