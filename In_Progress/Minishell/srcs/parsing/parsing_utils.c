#include "minishell.h"
#include "parsing.h"

char	is_escape(const char *str, int i)
{
	char bool;

	bool = 0;
	if (i == 0)
		return (0);
	i--;
	while (i >= 0 && str[i] == '\\')
	{
		bool = (char)!bool;
		i--;
	}
	return (bool);
}

int		skip_wp(char *input, int i)
{
	while (input[i] && ft_isspace(input[i]))
		i++;
	return (i);
}

int		skip_quote(const char *input, int i, char quote)
{
	i++;
	while ((input[i] && input[i] != quote) && !is_escape(input, i))
		i++;
	if (input[i])
		i++;
	return (i);
}

int		get_input(t_shell *shell, char **input)
{
	if (get_next_line(0, input) == 0)
	{
		input = NULL;
		shell->clear_env(shell);
		ft_putchar('\n');
		return (ERRCTRLD);
	}
	if (!input || !input[0])
	{
		free(input);
		input = NULL;
		return (ERREMPTY);
	}
	return (0);
}
