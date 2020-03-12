/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_disp_tree.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 10:30:08 by mlabouri          #+#    #+#             */
/*   Updated: 2020/03/12 18:50:35 by mlabouri         ###   ########          */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/trees.h"

int	disp_minus(struct s_f *bin, struct s_c arg, char conv)
{
	int			length;

	if (bin->minus < 0)
		bin->minus = ((bin->minus < 0) ? (bin->minus * -1) : bin->minus);
	if (bin->length >= bin->minus)
		return (0);
	if (!(bin->dotc))
		ft_disp_convs(arg, conv);
	length = bin->minus - bin->length;
	if (ft_cinset(conv, "di") && (int)arg.diux < 0)
		length--;
	while (length > 0)
	{
		ft_putchar_fd(' ', 1);
		length--;
	}
	return (1);
}

int	disp_zero(struct s_f *bin, struct s_c arg, char conv)
{
	int			length;

	if (bin->dotc || bin->zero < 0)
	{
		bin->pad = bin->zero;
		return (disp_pad(bin, arg, conv));
	}
	length = bin->zero - bin->length;
	if (ft_cinset(conv, "di") && (int)arg.diux < 0)
	{
		arg.diux = (unsigned long long)int_abs((int)arg.diux);
		length--;
	}
	if (length >= bin->zero)
		return (0);
	while (length > 0)
	{
		ft_putchar_fd('0', 1);
		length--;
	}
	if (ft_cinset(conv, "di") && (int)arg.diux < 0)
		ft_putnbr_fd((unsigned long)arg.diux, 1, 1);
	else
		ft_disp_convs(arg, conv);
	return (1);
}

int	disp_dot(struct s_f *bin, struct s_c arg, char conv)
{
	int length;

	length = bin->dot;
	if (ft_cinset(conv, INTS) && (arg.diux != 0 || bin->length != 0))
	{
		if (ft_cinset(conv, "di") && (int)arg.diux < 0)
			arg.diux = (unsigned long long)int_abs((int)arg.diux);
		while (length > 0)
		{
			ft_putchar_fd('0', 1);
			length--;
		}
		if (!(ft_cinset(conv, "di") && (int)arg.diux < 0))
			ft_disp_convs(arg, conv);
		else
			ft_putnbr_fd((unsigned long)arg.diux, 1, 1);
	}
	else if (conv == 's')
		ft_putnstr(arg.s, bin->dot);
	return (1);
}

int	disp_pad(struct s_f *bin, struct s_c arg, char conv)
{
	int			length;

	if (bin->pad < 0)
		bin->minus = ((bin->pad < 0) ? (bin->pad * -1) : bin->pad);
	length = bin->pad - bin->length;
	if (ft_cinset(conv, "di") && (int)arg.diux < 0)
		length--;
	if (bin->length >= bin->pad)
		return (0);
	while (length > 0)
	{
		ft_putchar_fd(' ', 1);
		length--;
	}
	return (0);
}
