/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 12:29:35 by dboyer            #+#    #+#             */
/*   Updated: 2020/05/08 17:53:29 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline int	ft_print(t_format format, va_list *va)
{
	if (format.converter == 'c')
		return (ft_print_char(format, va));
	else if (format.converter == 's')
		return (ft_print_str(format, va));
	else if (ft_cinset(format.converter, "di"))
		return (ft_print_nb(format, va));
	else if (ft_cinset(format.converter, "xX"))
		return (ft_print_nb_hex(format, va));
	else if (format.converter == 'p')
		return (ft_print_memory(format, va));
	else if (format.converter == 'u')
		return (ft_print_unsigned_nb(format, va));
	else if (format.converter == '%')
		return (ft_print_percent(format));
	return (0);
}
