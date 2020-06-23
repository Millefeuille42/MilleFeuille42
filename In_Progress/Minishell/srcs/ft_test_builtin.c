/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 17:02:19 by dboyer            #+#    #+#             */
/*   Updated: 2020/06/16 17:06:57 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_test_builtin(t_shell *shell, t_command *cmd_lst)
{
	int is_builtin;

	if ((is_builtin = ft_str_isequal(cmd_lst->command, "cd")))
		shell->ret = ft_cd(shell, cmd_lst->argv);
	else if ((is_builtin = ft_str_isequal(cmd_lst->command, "echo")))
		shell->ret = ft_echo(cmd_lst->argv);
	else if ((is_builtin = ft_str_isequal(cmd_lst->command, "pwd")))
		shell->ret = ft_pwd();
	else if ((is_builtin = ft_str_isequal(cmd_lst->command, "export")))
		shell->ret = ft_export(shell, cmd_lst->argv);
	else if ((is_builtin = ft_str_isequal(cmd_lst->command, "unset")))
		shell->ret = ft_unset(shell, cmd_lst->argv);
	else if ((is_builtin = ft_str_isequal(cmd_lst->command, "env")))
		shell->ret = ft_env(shell, cmd_lst->argv);
	return (is_builtin);
}
