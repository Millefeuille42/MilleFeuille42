/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_disp_tree.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 16:14:08 by mlabouri          #+#    #+#             */
/*   Updated: 2020/02/25 15:23:42 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/trees.h"

int	disp_minus(struct s_f *bin, struct s_c arg, char conv)
{
	int			length;

	if (bin->minus < 0)
		bin->minus = ABS(bin->minus);
	if (bin->length >= bin->minus)
		return (0);
	if (!(bin->dotc))
		ft_disp_convs(arg, conv);
	length = bin->minus - bin->length;
	if (ft_cinset(conv, "di") && (int)arg.diuxX < 0)
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
	if (ft_cinset(conv, "di") && (int)arg.diuxX < 0)
	{
		arg.diuxX = (unsigned long long)int_abs((int)arg.diuxX);
			length--;
	}
	if (length >= bin->zero)
		return (0);
	while (length > 0)
	{
		ft_putchar_fd('0', 1);
		length--;
	}
	if (ft_cinset(conv, "di") && (int)arg.diuxX < 0)
		ft_putnbr_fd((unsigned long)arg.diuxX, 1, 1);
	else
		ft_disp_convs(arg, conv);
	return (1);
}

int	disp_dot(struct s_f *bin, struct s_c arg, char conv)
{
	int length;

 	length = bin->dot;
	if (ft_cinset(conv, INTS) && (arg.diuxX != 0 || bin->length != 0))
	{
		if (ft_cinset(conv, "di") && (int)arg.diuxX < 0)
			arg.diuxX = (unsigned long long)int_abs((int)arg.diuxX);
		while (length > 0)
		{
			ft_putchar_fd('0', 1);
			length--;
		}
		if (!(ft_cinset(conv, "di") && (int)arg.diuxX < 0))
			ft_disp_convs(arg, conv);
		else
			ft_putnbr_fd((unsigned long)arg.diuxX, 1, 1);
	}
	else if (conv == 's')
		ft_putnstr(arg.s, bin->dot);
	return (1);
}

int	disp_pad(struct s_f *bin, struct s_c arg, char conv)
{
	int			length;

	if (bin->pad < 0)
		bin->minus = ABS(bin->pad);
	length = bin->pad - bin->length;
	if (ft_cinset(conv, "di") && (int)arg.diuxX < 0)
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

/*
 * - padding = with a l'envers
 *
 * priorité a la précision
 *
 * space = largeur - precision ou taille
 * si space < 0, rien afficher
*/