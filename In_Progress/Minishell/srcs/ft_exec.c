/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 11:00:05 by dboyer            #+#    #+#             */
/*   Updated: 2020/06/13 15:38:46 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "signal.h"

char	**ret_env(t_shell *shell)
{
	t_element	*cur;
	char		**envs;
	char		*key;
	int			i;

	if (!(envs = malloc(sizeof(char *) * (shell->env.size + 1))))
		return (NULL);
	cur = shell->env.first;
	i = 0;
	while (cur)
	{
		key = ft_strjoin(((t_env *)cur->content)->key, "=");
		envs[i] = ft_strjoin(key, ((t_env *)cur->content)->value);
		free(key);
		i++;
		cur = cur->next;
	}
	envs[i] = NULL;
	return (envs);
}

void	ft_exec(t_shell *shell, t_command *cmd, int i)
{
	pid_t		pid;
	char		**env;

	env = ret_env(shell);
	pid = fork();
	if (pid == -1)
	{
		ft_putstr_fd(strerror(errno), 2);
		exit(1);
	}
	if (pid == 0)
	{
		shell->ret = (int)ft_abs(execve(cmd[i].command, cmd[i].argv,
				env));
		while (cmd[i].end != 1)
		{
			if (cmd[i].argv)
				clear(cmd[i].argv);
			free(cmd[i].command);
			i++;
		}
		free(cmd);
		clear(env);
		shell->clear_env(shell);
		exit(0);
	}
	clear(env);
	wait(&shell->ret);
}
