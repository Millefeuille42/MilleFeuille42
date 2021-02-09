/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 17:00:59 by dboyer            #+#    #+#             */
/*   Updated: 2020/09/29 12:29:38 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_print_str(t_format format, va_list *va)
{
	char	*arg;
	int		length;
	int		result;

	arg = va_arg(*va, char*);
	arg = arg == NULL ? "(null)" : arg;
	length = (int)ft_strlen(arg);
	result = format.max < length && format.point ? format.max : length;
	format = ft_minmax_str(format, arg);
	result += ft_print_space_before(format);
	if (format.point)
		ft_putnstr(arg, format.max);
	else if (!format.point)
		ft_putstr(arg);
	result += ft_print_space_after(format);
	return (result);
}
