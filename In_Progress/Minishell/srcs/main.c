/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 11:20:36 by dboyer            #+#    #+#             */
/*   Updated: 2020/06/22 17:08:08 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

int	main(int argc, char *argv[], char *envp[])
{
	t_shell		shell;
	t_string	cwd;

	(void)argc;
	(void)argv;
	shell = ft_shell();
	start_env(&shell, envp);
	cwd = ft_getcwd();
	shell.replace_env(&shell, ft_strdup("SHELL"),
			ft_strjoin(cwd.content, "/minishell"));
	cwd.clear(&cwd);
	//shell.print_env(&shell);
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	shell.ret = 0;

	return (shell.run(&shell));
}
