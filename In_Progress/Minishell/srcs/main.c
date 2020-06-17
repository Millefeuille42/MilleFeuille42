/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 11:20:36 by dboyer            #+#    #+#             */
/*   Updated: 2020/06/16 15:09:25 by dboyer           ###   ########.fr       */
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

void 	c_handler(int sig)
{
	printf("%d SIGINT", sig);
	//shell->show_prompt;
}

void	q_handler(int sig)
{
	(void)sig;
	//(ONLY IF PROCESS RUNNING)
		//printf("Quit: %d\n", sig);
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
	shell.env_remove(&shell, "SHELL");
	shell.add_env(&shell, ft_strdup("SHELL"), ft_strjoin(cwd.content, "/minishell"));
	cwd.clear(&cwd);
	rc_parser(&shell, 0);
	//shell.print_env(&shell);
	signal(SIGINT, c_handler);
	signal(SIGQUIT, q_handler);
	shell.ret = 0;
	return (shell.run(&shell));
}
