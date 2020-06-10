/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 12:33:30 by dboyer            #+#    #+#             */
/*   Updated: 2020/05/08 17:52:27 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline int	ft_print_memory(t_format format, va_list *va)
{
	long	arg;
	int		result;

	arg = va_arg(*va, long);
	format = ft_minmax_memory(format, arg);
	result = ft_nbrlen_base(arg, 16);
	result = arg < 0 ? result + (16 - result) + 2 : result + 2;
	result += ft_print_space_before(format);
	ft_putstr("0x");
	result += ft_print_zero_padding(format);
	ft_putnbr_hex(arg, "0123456789abcdef", "ffffffffffffffff");
	result += ft_print_space_after(format);
	return (result);
}
