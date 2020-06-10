/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_nb.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 13:03:32 by dboyer            #+#    #+#             */
/*   Updated: 2020/05/09 13:55:54 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline void	ft_display(t_format format, unsigned int arg)
{
	if (format.point && format.max == 0 && arg == 0)
		return ;
	ft_putnbr_unsigned(arg);
}

int					ft_print_unsigned_nb(t_format format, va_list *va)
{
	unsigned int		arg;
	int					result;

	arg = va_arg(*va, unsigned int);
	format = ft_minmax_unsigned_nb(format, arg);
	if (format.point && format.max == 0 && arg == 0)
		result = 0;
	else
		result = ft_nbrlen_unsigned(arg);
	result += ft_print_space_before(format);
	result += ft_print_zero_padding(format);
	ft_display(format, arg);
	result += ft_print_space_after(format);
	return (result);
}
