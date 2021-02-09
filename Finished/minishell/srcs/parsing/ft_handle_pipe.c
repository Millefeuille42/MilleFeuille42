/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_pipe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 14:45:50 by dboyer            #+#    #+#             */
/*   Updated: 2020/10/29 11:33:36 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	exit_error_shell(t_shell *shell, char *msg)
{
	shell->clean(shell);
	perror(msg);
	exit(EXIT_FAILURE);
}

static char	*create_cmd(t_shell *shell, t_command *cmd, char *str)
{
	str = ft_get_command(str, shell, cmd);
	if (str)
		str = ft_parse_args(shell, str, cmd);
	else
	{
		safe_free((void **)&cmd->command);
		ft_print_error("%s << newline >>\n", SYNTAX_ERROR);
	}
	cmd->end = 1;
	return (str);
}

static void	exec(t_shell *shell, t_command *cmd)
{
	close(cmd->pipe[0]);
	dup2(cmd->pipe[1], STDOUT_FILENO);
	ft_exec(shell, cmd);
	exit(0);
}

char		*ft_handle_pipe(t_shell *shell, t_command *cmd, char *str)
{
	t_command	*cmd2;
	pid_t		pid;

	if (pipe(cmd->pipe) == -1)
		exit_error_shell(shell, "PIPE");
	if ((pid = fork()) == 0)
		exec(shell, cmd);
	else if (pid == -1)
		exit_error_shell(shell, "FORK");
	else if (pid > 0)
	{
		ft_close_fd(cmd);
		close(cmd->pipe[1]);
		cmd2 = ft_command();
		str = create_cmd(shell, cmd2, str);
		waitpid(pid, &shell->process_status, 1);
		if (ft_str_isequal(cmd2->command, "exit"))
			ft_safe_free((void **)&cmd2->command);
		cmd2->stdin = dup2(cmd->pipe[0], STDIN_FILENO);
		close(cmd->pipe[0]);
		shell->lst_cmd.append(&shell->lst_cmd, cmd2);
	}
	return (str);
}
