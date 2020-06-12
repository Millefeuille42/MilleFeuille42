/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 11:00:05 by dboyer            #+#    #+#             */
/*   Updated: 2020/06/12 12:29:32 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exec(t_shell *shell, char **cmd)
{
	pid_t		pid;
	const char	*env[] = { NULL };

	pid = fork();
	if (pid == -1)
	{
		ft_putstr_fd(strerror(errno), 2);
		exit(1);
	}
	if (pid == 0)
		shell->ret = (int)ft_abs(execve(cmd[0], cmd, (char **)env));
	wait(&pid);
}
