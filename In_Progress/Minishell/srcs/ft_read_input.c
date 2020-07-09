/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 17:33:38 by dboyer            #+#    #+#             */
/*   Updated: 2020/07/01 16:40:06 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parsing.h"

static  char	*safe_join(char *str1, char *str2, char *dest)
{
	t_string ret;

	ret = ft_string(str1);
	ret.push(&ret, "\n");
	ret.push(&ret, str2);
	if (dest)
		free(dest);
	return (ret.content);
}

static  int	ft_is_escape(char *str)
{
	int i;

	i = 0;
	--str;
	while (*str && *str == '\\')
	{
		str--;
		i++;
	}
	return (i % 2 != 0);
}

static  int	ft_is_quote(int c)
{
	return (c == '\'' || c == '\"');
}

static  int	ft_check_quote(char *input)
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

int		ft_read_input(t_shell *shell, char *next_input, char **ret)
{
	char	*input;
	int		res;

	if ((res = get_next_line(0, &input)) == 0 && ft_strlen(input) == 0 && ft_strlen(next_input) == 0)
	{
		if (next_input)
			free(next_input);
		if (input)
			free(input);
		shell->clear_env(shell);
		ft_putchar('\n');
		return (ERRCTRLD);
	}
	if (next_input)
		input = safe_join(next_input, input, input);
	free(next_input);
	next_input = input;
	if (!ft_check_quote(next_input))
	{
		ft_putstr("> ");
		return (ft_read_input(shell, next_input, ret));
	}
	input = ft_replace_input(shell, next_input);
	free(next_input);
	*ret = input;
	return (0);
}
