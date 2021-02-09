/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 09:18:06 by dboyer            #+#    #+#             */
/*   Updated: 2020/05/08 17:38:23 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *str, ...)
{
	int			i;
	char		*flag;
	va_list		va;
	t_format	format;

	i = 0;
	va_start(va, str);
	while (*str)
	{
		if (*str == '%' && (flag = ft_getflag(str)))
		{
			format = ft_format(flag, &va);
			i += ft_print(format, &va);
			str += ft_strlen(flag) - 1;
			free(flag);
		}
		else
		{
			ft_putchar(*str);
			i++;
		}
		str++;
	}
	va_end(va);
	return (i);
}
