/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 11:20:36 by dboyer            #+#    #+#             */
/*   Updated: 2020/07/09 10:16:56 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_shell shell;

void start_env(t_shell *shell, char **envp)
{
	int i;
	char **splitted;

	i = 0;
	while (envp[i])
	{
		splitted = ft_extract_env(envp[i]);
		if (splitted)
		{
			shell->add_env(shell, splitted[0], splitted[1]);
			free(splitted);
		}
		i++;
	}
}

void ft_handle_sigint(int sig)
{
	(void)sig;
	ft_putstr_fd("\b\b   \n", 0);
	shell.show_prompt(&shell);
}

void ft_handle_sigquit(int sig)
{
	(void)sig;
	ft_putstr_fd("\b\b  \b\b", 0);
}

int main(int argc, char *argv[], char *envp[])
{
	t_string cwd;

	(void)argc;
	(void)argv;
	shell = ft_shell();
	start_env(&shell, envp);
	cwd = ft_getcwd();
	shell.replace_env(&shell, ft_strdup("SHELL"),
					  ft_strjoin(cwd.content, "/minishell"));
	cwd.clear(&cwd);
	signal(SIGINT, ft_handle_sigint);
	signal(SIGQUIT, ft_handle_sigquit);
	return (shell.run(&shell));
}
