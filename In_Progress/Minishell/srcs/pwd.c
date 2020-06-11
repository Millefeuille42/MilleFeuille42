/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 11:40:54 by dboyer            #+#    #+#             */
/*   Updated: 2020/06/10 11:43:20 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void pwd(void)
{
    t_string dir;

    dir = ft_getcwd();
    ft_putstr(dir.content);
    ft_putchar('\n');
    dir.clear(&dir);
}
