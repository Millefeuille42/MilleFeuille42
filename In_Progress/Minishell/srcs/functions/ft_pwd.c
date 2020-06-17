/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 11:13:30 by dboyer            #+#    #+#             */
/*   Updated: 2020/06/16 14:56:54 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pwd(void)
{
	t_string dir;

	dir = ft_getcwd();
	ft_putstr(dir.content);
	ft_putchar('\n');
	dir.clear(&dir);
	return (0);
}
