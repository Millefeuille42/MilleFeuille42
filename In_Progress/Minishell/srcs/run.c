/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 16:18:02 by dboyer            #+#    #+#             */
/*   Updated: 2020/07/07 17:21:18 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parsing.h"

static int check_run_err(int err)
{
	if (err == ERRCTRLD)
		return (1);
	if (err == ERREMPTY || err == ERRMALLOC)
		return (2);
	if (err == ERRSYMBOL)
	{
		ft_printf("minishell: syntax error near unexpected token `;'\n");
		return (2);
	}
	if (err == ERRDBSYMBOL)
	{
		ft_printf("minishell: syntax error near unexpected token `;;'\n");
		return (2);
	}
	return (0);
}

int	run(t_shell *shell)
{
	int			i;
	int			err;
	char		exit;
	t_command	*cmd_lst;

	shell->show_prompt(shell);
	shell->replace_env(shell, ft_strdup("?"), ft_itoa(shell->ret));
	err = check_run_err(parse(shell, &cmd_lst));
	if (err == 1)
		return (0);
	else if (err == 2)
		return (run(shell));
	err = parse_redir(cmd_lst);
	err = clean_escape(cmd_lst);
	i = 0;
	exit = 0;
	while (cmd_lst && cmd_lst[i].end != 1)
	{
		if (!exit && ft_str_isequal(cmd_lst[i].command, "exit"))
			exit = 1;
		if (!exit && !ft_test_builtin(shell, &cmd_lst[i]))
		{
			if (!check_command(shell, &cmd_lst[i].command))
				shell->exec(shell, cmd_lst, i);
			else
			{
				shell->ret = 127;
				ft_printf("minishell: %s: No such file or directory\n", cmd_lst[i].command);
			}
		}
		if (cmd_lst[i].argv)
			clear(cmd_lst[i].argv);
		if (cmd_lst[i].command)
			free(cmd_lst[i].command);
		i++;
	}
	free(cmd_lst);
	if (!exit)
		return (run(shell));
	shell->clear_env(shell);
	return (0);
}
