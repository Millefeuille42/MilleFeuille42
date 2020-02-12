/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 16:09:27 by mlabouri          #+#    #+#             */
/*   Updated: 2020/02/12 16:49:36 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/trees.h"

void	ft_disp_convs(unsigned long long arg, char conv)
{
	if (ft_cinset(conv, INTS))
		disp_int(conv, arg);
	else
		(g_func_conv)[(int)conv](arg);
}

void	ft_disp_flags(struct s_f bin, unsigned long long arg, char conv)
{
	int	f;

	f = 0;
	if (bin.pad && !(bin.minus) && !(bin.zero))
		f = disp_pad(&bin, arg, conv);
	if (bin.zero && !(bin.minus))
		f = disp_zero(&bin, arg, conv);
	if (bin.dotc)
		f = disp_dot(&bin, arg, conv);
	if (bin.minus)
		f = disp_minus(&bin, arg, conv);
	if (f == 0)
		ft_disp_convs(arg, conv);
}