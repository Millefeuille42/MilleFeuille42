/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 18:51:09 by dboyer            #+#    #+#             */
/*   Updated: 2020/10/09 11:44:38 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_command	*ft_command(void)
{
	t_command	*this;

	if (!(this = (t_command *)ft_calloc(sizeof(t_command), 1)))
		return (NULL);
	this->end = 1;
	this->actual_fd = STDOUT_FILENO;
	this->stdin = STDIN_FILENO;
	this->stdout = this->actual_fd;
	this->stdout_saved = dup(STDOUT_FILENO);
	this->stdin_saved = dup(STDIN_FILENO);
	this->redirect.dest = ft_string("");
	this->redirect.type = 0;
	this->argv = ft_string("");
	return (this);
}
