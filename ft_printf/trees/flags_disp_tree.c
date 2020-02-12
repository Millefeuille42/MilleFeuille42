/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_disp_tree.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 16:14:08 by mlabouri          #+#    #+#             */
/*   Updated: 2020/02/12 17:23:45 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/trees.h"

int	disp_minus(struct s_f *bin, unsigned long long int arg, char conv)
{
	int			length;

	if (bin->minus < 0)
		bin->minus = ABS(bin->minus);
	if (bin->dotc && bin->dot >= bin->minus)
		return (1);

	if (bin->dot > 0)
		bin->minus = bin->minus - bin->dot + 1;
	if (ft_cinset(conv, INTS))
		length = bin->minus - length_int(conv, arg);
	else
		length = bin->minus - g_func_length[(int)conv](conv, arg);
	if (!(bin->dotc))
		ft_disp_convs(arg, conv);
	if (bin->dotc && bin->dot == 0 && arg == 0)
		length = bin->minus;
	while (length > 0)
	{
		ft_putchar_fd(' ', 1);
		length--;
	}
	return (1);
}

int	disp_zero(struct s_f *bin, unsigned long long int arg, char conv)
{
	int			length;

	if (bin->dotc || bin->zero < 0)
	{
		bin->pad = bin->zero;
		disp_pad(bin, arg, conv);
		return (1);
	}
	if (ft_cinset(conv, INTS))
		length = bin->zero - length_int(conv, arg);
	else
		length = bin->zero - g_func_length[(int)conv](conv, arg);
	if (ft_cinset(conv, "di") && (int)arg < 0)
		arg = (unsigned long long)int_abs((int)arg);
	while (length > 0)
	{
		ft_putchar_fd('0', 1);
		length--;
	}
	if (ft_cinset(conv, "di") && (int)arg < 0)
		ft_putnbr_fd((unsigned long)arg, 1, 1);
	else
		ft_disp_convs(arg, conv);
	return (1);
}

int	disp_dot(struct s_f *bin, unsigned long long int arg, char conv)
{
	int length;

	if (ft_cinset(conv, INTS) && (arg != 0 || bin->dot != 0))
	{
		length = bin->dot - length_int(conv, arg);
		if (ft_cinset(conv, "di") && (int) arg < 0)
		{
			arg = (unsigned long long) int_abs((int) arg);
			length ++;
		}
		while (length > 0)
		{
			ft_putchar_fd('0', 1);
			length--;
		}
		if (!(ft_cinset(conv, "di") && (int) arg < 0))
			ft_disp_convs(arg, conv);
		else
			ft_putnbr_fd((unsigned long int) arg, 1, 1);
	}
	else if (conv == 's')
		ft_putnstr((char *) arg, bin->dot);
	return (1);
}

int	disp_pad(struct s_f *bin, unsigned long long int arg, char conv)
{
	int			length;

	if (bin->pad < 0)
		bin->minus = ABS(bin->pad);
	if ((bin->dotc && bin->dot >= bin->pad) || bin->minus)
		return (0);
	if (bin->dot > 0)
		bin->pad = bin->pad - bin->dot + 1;
	if (ft_cinset(conv, INTS))
		length = bin->pad - length_int(conv, arg);
	else
		length = bin->pad - g_func_length[(int)conv](conv, arg);
	if (bin->dotc && bin->dot == 0 && arg == 0)
		length = bin->pad;
	while (length > 0)
	{
		ft_putchar_fd(' ', 1);
		length--;
	}
	return (0);
}

/*
 * Width < 0 == -Padding
 * - == 0padding null
 * 0padding = width si .
*/