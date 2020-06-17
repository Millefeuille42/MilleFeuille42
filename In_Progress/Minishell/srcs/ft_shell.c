/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shell.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 15:59:09 by dboyer            #+#    #+#             */
/*   Updated: 2020/06/15 11:35:58 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_shell	ft_shell(void)
{
	t_shell this;

	this.ret = 0;
	this.env = ft_list();
	this.print_env = ft_display_env;
	this.add_env = ft_add_env;
	this.run = run;
	this.show_prompt = ft_show_prompt;
	this.clear_env = ft_clear_env;
	this.env_get = ft_env_get;
	this.env_remove = ft_env_remove;
	this.replace_env = ft_replace_env;
	this.exec = ft_exec;
	return (this);
}
