/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 11:20:36 by dboyer            #+#    #+#             */
/*   Updated: 2020/10/29 11:49:25 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	t_shell	g_shell;

static	void	start_env(t_shell *shell_ng, char **envp)
{
	int		i;
	char	**splitted;

	i = 0;
	while (envp[i])
	{
		splitted = ft_extract_env(envp[i]);
		if (splitted)
		{
			shell_ng->add_env(shell_ng, splitted[0], splitted[1]);
			safe_free((void **)&splitted);
		}
		i++;
	}
}

static	void	ft_handle_sigterm(int sig)
{
	(void)sig;
	g_shell.clean(&g_shell);
	exit(143);
}

static	void	ft_handle_sigint(int sig)
{
	(void)sig;
	ft_putstr_fd("\n", STDIN_FILENO);
	safe_free((void **)&g_shell.input);
	if (wait(&g_shell.process_status) < 0 && !WIFSIGNALED(g_shell.process_status))
		g_shell.show_prompt(&g_shell);
	
	else
		g_shell.loop = 0;
}

static void		ft_handle_sigquit(int sig)
{
	(void)sig;
	ft_putstr_fd("\b\b  \b\b", STDIN_FILENO);
}

int				main(int argc, char *argv[], char *envp[])
{
	t_string cwd;

	(void)argc;
	(void)argv;
	g_shell = ft_shell();
	start_env(&g_shell, envp);
	cwd = ft_getcwd();
	g_shell.replace_env(&g_shell, ft_strdup("SHELL"),
			ft_strjoin(cwd.content, "/minishell"));
	signal(SIGQUIT, ft_handle_sigquit);
	signal(SIGINT, ft_handle_sigint);
	signal(SIGTERM, ft_handle_sigterm);
	cwd.clear(&cwd);
	return (g_shell.run(&g_shell));
}
