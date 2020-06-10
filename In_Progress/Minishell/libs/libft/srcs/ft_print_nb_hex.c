/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nb_hex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 13:14:11 by dboyer            #+#    #+#             */
/*   Updated: 2020/05/08 17:52:39 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline void	ft_display(t_format format, int arg)
{
	if (format.point && format.max == 0 && arg == 0)
		return ;
	if (format.converter == 'x')
		ft_putnbr_hex(arg, "0123456789abcdef", "ffffffff");
	else if (format.converter == 'X')
		ft_putnbr_hex(arg, "0123456789ABCDEF", "FFFFFFFF");
}

inline int			ft_print_nb_hex(t_format format, va_list *va)
{
	int		arg;
	int		result;

	arg = va_arg(*va, int);
	format = ft_minmax_nb_hex(format, arg);
	if (format.point && format.max == 0 && arg == 0)
		result = 0;
	else
		result = ft_nbrlen_base(arg, 16);
	result = arg < 0 ? result + (8 - result) : result;
	result += ft_print_space_before(format);
	result += ft_print_zero_padding(format);
	ft_display(format, arg);
	result += ft_print_space_after(format);
	return (result);
}
