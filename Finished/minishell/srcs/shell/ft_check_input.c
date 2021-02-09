/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 16:34:53 by dboyer            #+#    #+#             */
/*   Updated: 2020/10/27 15:51:57 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	int	ft_is_quote(int c)
{
	return (c == '\'' || c == '\"');
}

static int	ft_check_separator(char *input)
{
	char *tmp;

	tmp = ft_strtrim(input, " ");
	if (*tmp == '|')
		return (1);
	free(tmp);
	input = ft_strchr(input, '|');
	if (input)
	{
		if (ft_is_escape(input))
			return (ft_check_separator(++input));
		if (!(input = ft_move_until(++input, "not", ft_isspace)))
			return (0);
		return (ft_check_separator(input));
	}
	return (1);
}

static	int	ft_check_quote(char *input)
{
	char quote;

	if (!(input = ft_move_until(input, "is", ft_is_quote)))
		return (1);
	else if (ft_is_escape(input))
		return (ft_check_quote(++input));
	while (input)
	{
		quote = *input;
		input = ft_strchr(++input, quote);
		if (input && !ft_is_escape(input))
			return (1);
	}
	return (0);
}

int			ft_check_input(char *input)
{
	return (!ft_check_quote(input) ||\
			!ft_check_separator(input));
}
