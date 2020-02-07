/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convs_disp_tree.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 16:14:08 by mlabouri          #+#    #+#             */
/*   Updated: 2020/02/07 10:17:28 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/trees.h"

// diuxX
// c
// s
// p
// %

void	disp_int(char conv, unsigned long long int arg)
{
	if (ft_cinset(conv, "di"))
		ft_putnbr_fd((int) arg, 1);
	else if (ft_cinset(conv, "X"))
		ft_putnbrbase((int)arg, HEXX);
	else if (ft_cinset(conv, "x"))
		ft_putnbrbase((int)arg, HEX);
	else
		ft_putunbr((unsigned int)arg);
}

void	disp_char(char conv, unsigned long long int arg)
{
	ft_putchar_fd((char)arg, 1);
}

void	disp_string(char conv, unsigned long long int arg)
{
	ft_putstr_fd((char *)arg, 1);
}

void	disp_pointer(char conv, unsigned long long int arg)
{
	return;
}