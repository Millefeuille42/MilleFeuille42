/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 16:45:26 by dboyer            #+#    #+#             */
/*   Updated: 2020/10/09 11:56:56 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_del_cmd(t_element *element)
{
	t_command *cmd;

	cmd = (t_command *)element->content;
	if (cmd)
	{
		safe_free((void **)&cmd->command);
		cmd->argv.clear(&cmd->argv);
		cmd->redirect.dest.clear(&cmd->redirect.dest);
		safe_free((void **)&cmd);
	}
}
