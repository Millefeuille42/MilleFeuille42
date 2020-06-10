/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 12:37:27 by dboyer            #+#    #+#             */
/*   Updated: 2020/05/09 13:56:32 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline t_format	ft_convert_star(t_format format, va_list *va)
{
	format.min = !format.point ? va_arg(*va, int) : format.min;
	format.min_zero = format.min < 0 && format.min_zero ? 0 : format.min_zero;
	format.min = format.min < 0 && format.min_zero ? -format.min : format.min;
	format.max = format.point ? va_arg(*va, int) : format.max;
	format.point = format.max < 0 ? 0 : format.point;
	format.max = format.max < 0 ? 0 : format.max;
	return (format);
}

static inline t_format	ft_convert_minmax(t_format format, int i)
{
	if (format.flag[i] == '0')
	{
		format.min_zero = !format.point ? 1 : format.min_zero;
		format.max_zero = format.point ? 1 : format.max_zero;
	}
	format.min = !format.point ? ft_atoi(&format.flag[i]) : format.min;
	format.max = format.point ? ft_atoi(&format.flag[i]) : format.max;
	return (format);
}

inline t_format			ft_parsing(t_format format, va_list *va)
{
	int i;

	i = 0;
	while (format.flag[i])
	{
		format.inversed = format.flag[i] == '-' ? 1 : format.inversed;
		format.point = format.flag[i] == '.' ? 1 : format.point;
		if (format.flag[i] == '*')
		{
			format = ft_convert_star(format, va);
			format.inversed = format.min < 0 ? 1 : format.inversed;
		}
		else if (ft_isdigit(format.flag[i]))
		{
			format = ft_convert_minmax(format, i);
			while (ft_isdigit(format.flag[i]))
				i++;
			i--;
		}
		i++;
	}
	format.min = format.inversed && format.min > 0 ? -format.min : format.min;
	format.max = !format.point ? 0 : format.max;
	format.converter = format.flag[i - 1];
	return (format);
}
