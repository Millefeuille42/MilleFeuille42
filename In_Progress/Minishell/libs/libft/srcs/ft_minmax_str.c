/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minmax_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 12:28:11 by dboyer            #+#    #+#             */
/*   Updated: 2020/05/08 17:50:57 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline t_format	ft_minmax_str(t_format format, char *arg)
{
	int	strlen;

	strlen = (int)ft_strlen(arg);
	format.max = strlen == 0 && arg != NULL ? strlen : format.max;
	if (format.max < strlen && format.point)
		format.zero_padding = format.max;
	else
		format.zero_padding = strlen;
	if (format.min > 0)
	{
		if (format.min > format.zero_padding)
			format.space_padding = format.min - format.zero_padding;
		else
			format.space_padding = 0;
	}
	else if (format.min < 0)
	{
		if (-format.min > format.zero_padding)
			format.space_padding = format.min + format.zero_padding;
		else
			format.space_padding = 0;
	}
	return (format);
}
