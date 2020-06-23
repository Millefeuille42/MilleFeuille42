#include "minishell.h"
#include "parsing.h"

int		get_next_arg(char *input, int *s, char **str)
{
	int		i;

	*s = skip_wp(input, *s);
	i = *s;
	while (!ft_isspace(input[i]) && input[i])
	{
		if ((input[i] == '"' || input[i] == '\'') && !is_escape(input, i))
		{
			i = skip_quote(input, i, input[i]);
			break ;
		}
		i++;
	}
	if (!(*str = ft_substr(input, *s, i - *s)))
		return (-ERRMALLOC);
	*s = i;
	if (!*str[0])
	{
		free(*str);
		*str = NULL;
		return (0);
	}
	return (0);
}
