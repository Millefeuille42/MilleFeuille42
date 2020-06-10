/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 10:45:44 by dboyer            #+#    #+#             */
/*   Updated: 2020/05/08 17:48:43 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline t_format	ft_format(char *flag, va_list *va)
{
	t_format format;

	format.flag = &(flag[1]);
	format.point = 0;
	format.inversed = 0;
	format.min = 0;
	format.max = 0;
	format.max_zero = 0;
	format.min_zero = 0;
	format.space_padding = 0;
	format.zero_padding = 0;
	format = ft_parsing(format, va);
	return (format);
}
