/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_prompt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 16:29:28 by dboyer            #+#    #+#             */
/*   Updated: 2020/10/28 08:56:47 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*format(char *path)
{
	t_string	format;

	format = ft_string("(minishell) [");
	format.push(&format, path);
	format.push(&format, "] - $ ");
	return (format.content);
}

void		ft_show_prompt(t_shell *shell)
{
	char	*home;
	char	*output;

	home = shell->env_get(shell, "HOME");
	shell->prompt = ft_string(shell->env_get(shell, "PWD"));
	if (home)
		shell->prompt.replace(&shell->prompt, home, "~", -1);
	output = format(shell->prompt.content);
	ft_putstr_fd(output, STDIN_FILENO);
	free(output);
	shell->prompt.clear(&shell->prompt);
}
