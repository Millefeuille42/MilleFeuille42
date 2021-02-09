/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_zero_padding.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 13:10:01 by dboyer            #+#    #+#             */
/*   Updated: 2020/09/29 12:29:38 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_zero_padding(t_format format)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (format.space_padding > 0 && format.min_zero && !format.point)
		while (i < format.space_padding)
		{
			ft_putchar('0');
			i++;
		}
	if (format.zero_padding > 0)
		while (j < format.zero_padding)
		{
			ft_putchar('0');
			j++;
		}
	return (i + j);
}
