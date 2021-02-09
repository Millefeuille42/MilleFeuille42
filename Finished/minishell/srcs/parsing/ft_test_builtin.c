/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 17:02:19 by dboyer            #+#    #+#             */
/*   Updated: 2020/10/21 17:38:26 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	int	check_and_run(t_shell *shell, t_command *cmd_lst,\
		char *cmd, char **argv)
{
	int ret;

	ret = 0;
	if ((ret = ft_str_isequal(cmd, "cd")))
		shell->ret = ft_cd(shell, argv);
	else if ((ret = ft_str_isequal(cmd, "echo")))
		shell->ret = ft_echo(argv);
	else if ((ret = ft_str_isequal(cmd, "pwd")))
		shell->ret = ft_pwd(shell);
	else if ((ret = ft_str_isequal(cmd, "export")))
		shell->ret = ft_export(shell, argv);
	else if ((ret = ft_str_isequal(cmd, "unset")))
		shell->ret = ft_unset(shell, argv);
	else if ((ret = ft_str_isequal(cmd, "env")))
		shell->ret = ft_env(shell, argv);
	else if ((ret = ft_str_isequal(cmd_lst->command, "exit")))
		shell->ret = ft_exit(shell, argv);
	return (ret);
}

int			ft_test_builtin(t_shell *shell, t_command *cmd_lst)
{
	int		is_builtin;
	char	**splitted;
	char	**argv;
	int		len;

	is_builtin = 0;
	if (cmd_lst->command)
	{
		splitted = ft_split(cmd_lst->command, '/');
		len = ft_len(splitted);
		argv = ft_sort_arg(cmd_lst->argv.content);
		if (len)
			is_builtin = check_and_run(shell, cmd_lst, splitted[len - 1], argv);
		else
		{
			is_builtin = 0;
			cmd_lst->command = NULL;
		}
		ft_split_clean(&argv);
		ft_split_clean(&splitted);
	}
	return (is_builtin);
}
