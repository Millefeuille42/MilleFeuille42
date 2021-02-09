/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 15:19:13 by dboyer            #+#    #+#             */
/*   Updated: 2020/09/29 12:29:37 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_print_char(t_format format, va_list *va)
{
	int		arg;
	int		result;

	arg = va_arg(*va, int);
	result = 1;
	format = ft_minmax(format, 1);
	result += ft_print_space_before(format);
	result += ft_print_zero_padding(format);
	ft_putchar(arg);
	result += ft_print_space_after(format);
	return (result);
}
