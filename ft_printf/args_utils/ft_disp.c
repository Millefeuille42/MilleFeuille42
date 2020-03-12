/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 10:30:08 by mlabouri          #+#    #+#             */
/*   Updated: 2020/03/12 18:50:35 by mlabouri         ###   ########          */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/trees.h"

void	ft_disp_convs(struct s_c arg, char conv)
{
	if (ft_cinset(conv, INTS))
		disp_int(conv, arg);
	else
		(g_func_conv)[(int)conv](arg);
}

void	ft_disp_flags(struct s_f bin, struct s_c arg, char conv)
{
	int	disp;

	disp = 0;
	if (bin.dot < 0 || conv == 'c')
		bin.dotc = 0;
	if (ft_cinset(conv, INTS))
		bin.length = length_int(conv, arg, &bin);
	else
		bin.length = g_func_length[(int)conv](conv, arg, &bin);
	if (bin.pad && !(bin.minus) && !(bin.zero))
		disp = disp + disp_pad(&bin, arg, conv);
	if (bin.zero && !(bin.minus))
		disp = disp + disp_zero(&bin, arg, conv);
	if (bin.dotc)
		disp = disp + disp_dot(&bin, arg, conv);
	if (bin.minus)
		disp = disp + disp_minus(&bin, arg, conv);
	if (disp == 0)
		ft_disp_convs(arg, conv);
}
