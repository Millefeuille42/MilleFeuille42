/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 12:59:08 by dboyer            #+#    #+#             */
/*   Updated: 2020/10/29 11:41:00 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	t_command	*get_last(t_list *list)
{
	return (list->size ? (t_command *)(list->last->content) : NULL);
}

static	void		exec(t_shell *shell, t_command *cmd)
{
	ft_exec(shell, cmd);
	cmd->end = 0;
	shell->lst_cmd.iter(shell->lst_cmd.first, ft_del_cmd);
	shell->lst_cmd.clear(&shell->lst_cmd);
}

static	char		*create_cmd(t_shell *shell, char *str)
{
	t_command	*cmd;

	cmd = ft_command();
	str = ft_get_command(str, shell, cmd);
	str = ft_parse_args(shell, str, cmd);
	cmd->end = 1;
	shell->lst_cmd.append(&shell->lst_cmd, cmd);
	return (str);
}

static	char		*handle_symbole(t_shell *shell, t_command *cmd, char *str)
{
	if (cmd && *str == '>' && !ft_is_escape(str))
		str = ft_handle_stdout_redirect(shell, cmd, str);
	else if (cmd && *str == '<' && !ft_is_escape(str))
		str = ft_handle_stdin_redirect(shell, cmd, str);
	else if (cmd && *str == '|' && !ft_is_escape(str))
		str = ft_handle_pipe(shell, cmd, str);
	else if (!cmd || (cmd && !cmd->end))
		str = create_cmd(shell, str);
	return (str);
}

int					ft_parse_input(t_shell *shell, char *str)
{
	t_command	*cmd;

	str = ft_move_until(str, "not", ft_isspace);
	if (str && *str && ft_isseparator(*str))
	{
		ft_syntax_error(shell);
		shell->loop = 0;
	}
	while (shell->loop)
	{
		cmd = get_last(&shell->lst_cmd);
		if (cmd && ((str && *str == ';') || (str && !*str) || !str))
		{
			exec(shell, cmd);
			if (str && *str)
				str++;
			else
				shell->loop = 0;
		}
		else if (str && (str = ft_move_until(str, "not", ft_isspace)))
			str = handle_symbole(shell, cmd, str);
		else
			shell->loop = 0;
	}
	return (0);
}
