/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minmax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 12:06:25 by dboyer            #+#    #+#             */
/*   Updated: 2020/05/08 17:51:12 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline t_format	ft_minmax(t_format format, int nbrlen)
{
	format.zero_padding = format.max > nbrlen ? format.max - nbrlen : 0;
	if (format.min > 0)
	{
		if (format.min > nbrlen + format.zero_padding)
			format.space_padding = format.min - format.zero_padding - nbrlen;
		else
			format.space_padding = 0;
	}
	else if (format.min < 0)
	{
		if (-format.min > nbrlen + format.zero_padding)
			format.space_padding = format.min + format.zero_padding + nbrlen;
		else
			format.space_padding = 0;
	}
	return (format);
}
