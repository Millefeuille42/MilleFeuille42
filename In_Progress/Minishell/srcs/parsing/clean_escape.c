//
// Created by Mathieu LABOURIER on 7/9/20.
//

#include "parsing.h"
#include "minishell.h"

int		clean_escape_str(char **str)
{
	int	i;
	int err;

	i = ft_strlen(*str);
	while (i > 0)
	{
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