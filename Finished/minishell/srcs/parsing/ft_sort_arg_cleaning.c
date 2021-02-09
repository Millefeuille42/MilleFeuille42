/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_arg_cleaning.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 10:04:49 by mlabouri          #+#    #+#             */
/*   Updated: 2020/10/21 17:38:26 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	char	to_escape(char c)
{
	return ((char)(c * (ft_isalnum(c) + ft_isspace(c) + c == '\'')));
}

char			*clean_backslash(char *str)
{
	t_string	temp;
	int			i;
	char		is_q[2];

	temp = ft_string(str);
	i = (int)temp.size - 1;
	is_q[0] = 0;
	is_q[1] = 0;
	while (i >= 0)
	{
		if (str[i] == -2 && !is_escape(str, i))
			is_q[0] = (char)!is_q[0];
		if (str[i] == -1 && !is_escape(str, i))
			is_q[1] = (char)!is_q[1];
		if (!is_escape(str, i) && str[i] == '\\'
				&& ((is_q[0] && !to_escape(str[i + 1]))
				|| (!is_q[0] && !is_q[1])))
			temp.content[i] = -1;
		i--;
	}
	temp.delete(&temp, "\376", temp.size);
	temp.delete(&temp, "\377", temp.size);
	return (temp.content);
}

char			*clean_quotes(char *str)
{
	t_string	temp;
	int			i[2];
	char		spec;

	temp = ft_string(str);
	i[0] = 0;
	while (str[i[0]])
	{
		if ((!is_escape(str, i[0]) && (str[i[0]] == '"' || str[i[0]] == '\'')))
		{
			i[1] = i[0];
			i[0] = skip_quote(temp.content, i[0], str[i[0]]) - 1;
			if ((spec = -1) && str[i[0]] == '"' && !is_escape(str, i[0]))
				spec = -2;
			temp.content[i[0]] = spec;
			temp.content[i[1]] = spec;
		}
		i[0]++;
	}
	return (temp.content);
}

char			**clean_args(char **args)
{
	int		i;
	char	*temp;

	i = 0;
	while (args[i])
	{
		if ((temp = clean_quotes(args[i])))
		{
			safe_free((void **)&args[i]);
			args[i] = temp;
		}
		if ((temp = clean_backslash(args[i])))
		{
			safe_free((void **)&args[i]);
			args[i] = temp;
		}
		i++;
	}
	return (args);
}
