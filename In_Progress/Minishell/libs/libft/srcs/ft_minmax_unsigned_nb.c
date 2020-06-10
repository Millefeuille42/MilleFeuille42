/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minmax_unsigned_nb.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 12:06:25 by dboyer            #+#    #+#             */
/*   Updated: 2020/05/08 17:51:05 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline t_format	ft_minmax_unsigned_nb(t_format format, unsigned int arg)
{
	int	nbrlen;

	nbrlen = (int)ft_nbrlen_unsigned(arg);
	nbrlen = format.point && format.max == 0 && arg == 0 ? 0 : nbrlen;
	format = ft_minmax(format, nbrlen);
	return (format);
}
