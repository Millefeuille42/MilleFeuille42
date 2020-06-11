/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shell.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 15:59:09 by dboyer            #+#    #+#             */
/*   Updated: 2020/06/11 16:30:57 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

t_shell ft_shell(void)
{
    t_shell this;

    this.ret = 0;
    this.cwd = NULL;
    this.env = ft_list();
    this.print_env = ft_display_env;
    this.add_env = ft_add_env;
    this.run = run;
    this.show_prompt = ft_show_prompt;
    return (this);
}
