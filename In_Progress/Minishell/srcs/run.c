/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 16:18:02 by dboyer            #+#    #+#             */
/*   Updated: 2020/06/16 18:06:49 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	run(t_shell *shell)
{
	int			i;
	char		exit;
	char		*input;
	t_command	*cmd_lst;

	shell->show_prompt(shell);
	shell->replace_env(shell, ft_strdup("?"), ft_itoa(shell->ret));
	if (get_next_line(0, &input) == 0)
	{
		free(input);
		shell->clear_env(shell);
		ft_putchar('\n');
		return (0);
	}
	if (!input[0])
	{
		free(input);
		return (run(shell));
	}
	cmd_lst = parse_command(input);
	if (cmd_lst == NULL || clean_command(shell, cmd_lst) < 0)
	{
		ft_printf("ERROR\n");
		return (run(shell));
	}
	i = 0;
	exit = 0;
	if (!ft_test_builtin(shell, cmd_lst))
	{
		while (cmd_lst && cmd_lst[i].end != 1)
		{
			if (!exit && ft_str_isequal(cmd_lst[i].command.content, "exit"))
				exit = 1;
			if (!exit)
			{
				if (!check_command(shell, &cmd_lst[i].command))
					shell->exec(shell, cmd_lst, i);
				else
				{
					shell->ret = 127;
					ft_printf("minishell: %s: No such file or directory\n", cmd_lst[i].command.content);
				}
			}
			if (cmd_lst[i].argv)
				clear(cmd_lst[i].argv);
			cmd_lst[i].command.clear(&cmd_lst[i].command);
			i++;
		}
	}
	free(cmd_lst);
	if (!exit)
		return (run(shell));
	shell->clear_env(shell);
	return (0);
}
