/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shell.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 15:59:09 by dboyer            #+#    #+#             */
/*   Updated: 2020/10/28 19:10:01 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_shell	ft_shell(void)
{
	t_shell this;

	this.ret = 0;
	this.exit = 0;
	this.loop = 1;
	this.env = ft_list();
	this.lst_cmd = ft_list();
	this.print_env = ft_display_env;
	this.add_env = ft_add_env;
	this.run = ft_run;
	this.show_prompt = ft_show_prompt;
	this.clear_env = ft_clear_env;
	this.env_get = ft_env_get;
	this.env_remove = ft_env_remove;
	this.replace_env = ft_replace_env;
	this.clean = ft_clean_shell;
	this.input = NULL;
	return (this);
}
