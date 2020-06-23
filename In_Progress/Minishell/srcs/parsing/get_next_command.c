#include "minishell.h"
#include "parsing.h"

int		get_next_command(char *input, int *s, char **str)
{
	int i;

	*s = skip_wp(input, *s);
	i = *s;
	if (input[0] == ';')
		return (-ERRSYMBOL);
	if (ft_strnstr(input, ";;", ft_strlen(input)))
		return (-ERRDBSYMBOL);
	while (input[i] != ';' && input[i])
	{
		if ((input[i] == '"' || input[i] == '\'') && !is_escape(input, i))
			i = skip_quote(input, i, input[i]) - 1;
		i++;
	}
	if (!(*str = ft_substr(input, *s, i - *s)))
		return (-ERRMALLOC);
	if ((*s = i) && input[i])
		*s = i + 1;
	if (!(*str)[0])
	{
		free(*str);
		*str = NULL;
		return (0);
	}
	return (0);
}
