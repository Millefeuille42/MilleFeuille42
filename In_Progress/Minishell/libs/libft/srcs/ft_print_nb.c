/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 10:49:57 by dboyer            #+#    #+#             */
/*   Updated: 2020/05/08 17:52:46 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline void	ft_display(t_format format, int arg)
{
	if (format.point && format.max == 0 && arg == 0)
		return ;
	ft_putnbr_fd(arg, 1);
}

inline int			ft_print_nb(t_format format, va_list *va)
{
	int		arg;
	int		result;

	arg = va_arg(*va, int);
	format = ft_minmax_nb(format, arg);
	if (format.point && format.max == 0 && arg == 0)
		result = 0;
	else
		result = ft_nbrlen(arg);
	result += ft_print_space_before(format);
	if (arg < 0)
	{
		ft_putchar('-');
		result++;
	}
	result += ft_print_zero_padding(format);
	ft_display(format, arg);
	result += ft_print_space_after(format);
	return (result);
}
