/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 17:33:38 by dboyer            #+#    #+#             */
/*   Updated: 2020/10/29 12:24:09 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	char	*safe_join(char *str1, char *str2)
{
	t_string ret;

	ret = ft_string(str1);
	ret.push(&ret, "\n");
	ret.push(&ret, str2);
	safe_free((void **)&str1);
	safe_free((void **)&str2);
	return (ret.content);
}

int				ft_read_input(t_shell *shell)
{
	char	*input;

	input = NULL;
	if (get_next_line(0, &input) == 0 && !shell->input)
	{
		shell->exit = 1;
		shell->input = input;
		return (0);
	}
	if (shell->input)
		shell->input = safe_join(shell->input, input);
	else
		shell->input = input;
	if (ft_check_input(shell->input))
	{
		ft_putstr("> ");
		return (ft_read_input(shell));
	}
	return (0);
}
