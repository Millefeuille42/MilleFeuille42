/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 11:00:05 by dboyer            #+#    #+#             */
/*   Updated: 2020/10/29 12:01:47 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	void	exit_error_shell(t_shell *shell, char *msg)
{
	perror(msg);
	shell->clean(shell);
	exit(EXIT_FAILURE);
}

static	void	clean_env_argv(char ***envp, char ***argv)
{
	ft_split_clean(envp);
	ft_split_clean(argv);
}

static	void	command_not_found(t_shell *shell, t_command *cmd)
{
	ft_print_error("minishell : %s: commande introuvable\n", cmd->command);
	shell->clean(shell);
}

static	void	exec(t_shell *shell, t_command *cmd, char ***envp, char ***argv)
{
	int	status;

	if ((shell->pid = fork()) == -1)
	{
		clean_env_argv(envp, argv);
		exit_error_shell(shell, "FORK");
	}
	if (shell->pid == 0)
	{
		if (cmd->command && execve(cmd->command, *argv, *envp) < 0)
		{
			command_not_found(shell, cmd);
			clean_env_argv(envp, argv);
			exit(EXIT_FAILURE);
		}
		exit(EXIT_SUCCESS);
	}
	else if (shell->pid > 0)
	{
		if (waitpid(shell->pid, &status, 0) >= 0 &&\
			WIFEXITED(status))
			shell->ret = WEXITSTATUS(status);
	}
	clean_env_argv(envp, argv);
}

void			ft_exec(t_shell *shell, t_command *cmd)
{
	char **envp;
	char **argv;

	if (!ft_test_builtin(shell, cmd))
	{
		envp = ft_ret_env(shell);
		argv = ft_sort_arg(cmd->argv.content);
		exec(shell, cmd, &envp, &argv);
	}
	ft_close_fd(cmd);
}
