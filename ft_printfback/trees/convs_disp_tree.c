/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convs_disp_tree.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 16:14:08 by mlabouri          #+#    #+#             */
/*   Updated: 2020/02/10 11:36:05 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/trees.h"

void	disp_int(char conv, unsigned long long int arg)
{
	if (ft_cinset(conv, "di"))
		ft_putnbr_fd((int)arg, 1);
	else if (conv == 'X')
		ft_putnbrbase((unsigned int)arg, HEXX);
	else if (ft_cinset(conv, "x"))
		ft_putnbrbase((unsigned long)arg, HEX);
	else
		ft_putunbr((unsigned int)arg);
}

void	disp_char(unsigned long long int arg)
{
	ft_putchar_fd((char)arg, 1);
}

void	disp_string(unsigned long long int arg)
{
	ft_putstr_fd((char *)arg, 1);
}

void	disp_pointer(unsigned long long int arg)
{
	ft_putstr_fd("0x", 1);
	disp_int('x', arg);
}
