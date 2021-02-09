/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minmax_nb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 12:06:25 by dboyer            #+#    #+#             */
/*   Updated: 2020/09/29 12:29:36 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_format	ft_minmax_nb(t_format format, int arg)
{
	int	nbrlen;

	if (format.point && format.max == 0 && arg == 0)
		nbrlen = 0;
	else
		nbrlen = (int)ft_nbrlen(arg);
	format = ft_minmax(format, nbrlen);
	if (format.space_padding > 0 && arg < 0)
		format.space_padding = format.space_padding - 1;
	else if (format.space_padding < 0 && arg < 0)
		format.space_padding = format.space_padding + 1;
	return (format);
}
