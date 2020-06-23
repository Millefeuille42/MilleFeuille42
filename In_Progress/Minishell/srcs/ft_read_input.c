/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 17:33:38 by dboyer            #+#    #+#             */
/*   Updated: 2020/06/22 17:00:47 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static inline int	ft_is_escape(char *str)
{
	int i;

	i = 0;
	--str;
	while (*str && *str == '\\')
	{
		str--;
		i++;
	}
	return (!(i % 2 == 0));
}

static inline int	ft_is_quote(int c)
{
	return (c == '\'' || c == '\"');
}

static inline int	ft_check_quote(char *input)
{
	int i;

	i = 1;
	input = ft_move_until(input, "is", ft_is_quote);
	if (input && ft_is_escape(input))
		return (ft_check_quote(++input));
	if (input)
	{
		while (input[i])
		{
			if (input[i] == input[0] && !ft_is_escape(&input[i]))
				return (1);
			i++;
		}
		return (0);
	}
	return (1);
}

char				*ft_read_input(t_shell *shell, char *next_input)
{
	char	*input;

	if (get_next_line(0, &input) == 0)
	{
		if (next_input)
			free(next_input);
		if (input)
			free(input);
		shell->clear_env(shell);
		ft_putchar('\n');
		return (NULL);
	}
	if (next_input)
		input = ft_strjoin(next_input, input);
	free(next_input);
	next_input = input;
	if (!ft_check_quote(next_input))
	{
		ft_putstr("> ");
		return (ft_read_input(shell, next_input));
	}
	return (next_input);
}
