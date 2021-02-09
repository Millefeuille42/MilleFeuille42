/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 11:31:18 by dboyer            #+#    #+#             */
/*   Updated: 2020/10/09 11:31:24 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_close_fd(t_command *cmd)
{
	if (cmd->actual_fd > 0)
		close(cmd->actual_fd);
	if (cmd->stdin > 0)
		close(cmd->stdin);
	if (cmd->stdout > 0)
		close(cmd->stdout);
	dup2(cmd->stdout_saved, STDOUT_FILENO);
	dup2(cmd->stdin_saved, STDIN_FILENO);
}
