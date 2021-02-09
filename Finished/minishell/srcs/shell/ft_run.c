/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 16:18:02 by dboyer            #+#    #+#             */
/*   Updated: 2020/10/29 12:27:31 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	void	prompt(t_shell *shell)
{
	shell->loop = 1;
	shell->show_prompt(shell);
	ft_read_input(shell);
	if (shell->input)
	{
		ft_parse_input(shell, shell->input);
		shell->replace_env(shell, ft_strdup("?"), ft_itoa(shell->ret));
		shell->lst_cmd.iter(shell->lst_cmd.first, ft_del_cmd);
		shell->lst_cmd.clear(&shell->lst_cmd);
		safe_free((void **)&shell->input);
	}
}

int				ft_run(t_shell *shell)
{
	int loop_wait;

	if (!shell->exit)
	{
		prompt(shell);
		while (wait(&shell->process_status) >= 0)
			loop_wait = 1;
		return (shell->run(shell));
	}
	shell->clean(shell);
	ft_putstr_fd("exit\n", STDIN_FILENO);
	return (shell->exit_code);
}
