/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convs_disp_tree.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 14:06:41 by mlabouri          #+#    #+#             */
/*   Updated: 2020/04/10 14:06:41 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/trees.h"

void	disp_int(char conv, struct s_c arg)
{
	if (ft_cinset(conv, "di"))
		ft_putnbr_fd((unsigned long)arg.diux, 1, 0);
	else if (conv == 'X')
		ft_putnbrbase((unsigned)arg.diux, HEXX);
	else if (ft_cinset(conv, "x"))
		ft_putnbrbase((unsigned)arg.diux, HEX);
	else
		ft_putunbr((unsigned long)arg.diux);
}

void	disp_char(struct s_c arg)
{
	ft_putchar_fd(arg.ch, 1);
}

void	disp_string(struct s_c arg)
{
	ft_putstr_fd(arg.s, 1);
}

void	disp_pointer(struct s_c arg)
{
	ft_putstr_fd("0x", 1);
	ft_putnbrbase(arg.p, HEX);
}
