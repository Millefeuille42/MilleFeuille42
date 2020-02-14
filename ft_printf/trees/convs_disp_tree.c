/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convs_disp_tree.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 16:14:08 by mlabouri          #+#    #+#             */
/*   Updated: 2020/02/14 13:43:07 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/trees.h"

void	disp_int(char conv, struct s_c arg)
{
	if (ft_cinset(conv, "di"))
		ft_putnbr_fd((unsigned long)arg.diuxX, 1, 0);
	else if (conv == 'X')
		ft_putnbrbase((unsigned long)arg.diuxX, HEXX);
	else if (ft_cinset(conv, "x"))
		ft_putnbrbase((unsigned long)arg.diuxX, HEX);
	else
		ft_putunbr((unsigned long)arg.diuxX);
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
