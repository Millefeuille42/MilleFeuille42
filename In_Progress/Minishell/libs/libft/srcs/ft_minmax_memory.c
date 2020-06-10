/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minmax_memory.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 09:40:05 by dboyer            #+#    #+#             */
/*   Updated: 2020/05/08 17:50:41 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline t_format	ft_minmax_memory(t_format format, long arg)
{
	int	nbrlen;

	nbrlen = (int)ft_nbrlen_base(arg, 16);
	nbrlen = arg < 0 ? nbrlen + (16 - nbrlen) + 2 : nbrlen + 2;
	format.max = format.max > 0 ? format.max + 2 : format.max;
	format = ft_minmax(format, nbrlen);
	return (format);
}
