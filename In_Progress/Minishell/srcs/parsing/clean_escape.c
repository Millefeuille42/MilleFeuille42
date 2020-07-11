//
// Created by Mathieu LABOURIER on 7/9/20.
//

#include "parsing.h"
#include "minishell.h"

int		clean_escape_in_quote(char **str, int *i, char quote)
{
	int err;

	if ((err = delete_char(str, *i)))
		return (err);
	while (*i > 0 && !((*str)[*i] == quote && !is_escape(*str, *i)))
	{
		if (((*str)[*i]) == '\\' && is_escape(*str, *i))
		{
			if ((err = delete_char(str, *i)))
				return (err);
		}
		*i -= 1;
	}
	if ((*str)[*i] == quote && !is_escape(*str, *i))
		if ((err = delete_char(str, *i)))
			return (err);
	return (0);
}

int		clean_escape_str(char **str)
{
	int	i;
	int err;

	i = ft_strlen(*str);
	while (i > 0)
	{
		if (ft_cinset((*str)[i], "\"'") && !is_escape(*str, i))
		{
			clean_escape_in_quote(str, &i, (*str)[i]);
			continue ;
		}
		if (is_escape(*str, i))
		{
			if ((err = delete_char(str, i-1)))
				return (err);
			i--;
		}
		i--;
	}
	return (0);
}

int 	clean_escape(t_command *cmd_lst)
{
	int	i;
	int	i2;
	int err;

	i = 0;
	while (!cmd_lst[i].end)
	{
		i2 = 0;
		while (cmd_lst[i].argv[i2])
		{
			if ((err = clean_escape_str(&cmd_lst[i].argv[i2])))
				return (err);
			i2++;
		}
		i++;
	}
	return (0);
}