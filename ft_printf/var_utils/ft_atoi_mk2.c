/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_mk2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 10:30:08 by mlabouri          #+#    #+#             */
/*   Updated: 2020/03/10 08:34:43 by mlabouri         ###   ########          */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		atoi_mk2(const char *s, int start, int end)
{
	int res;
	int power;

	power = end - start;
	res = 0;
	while (power >= 0)
	{
		res = res + ((int)s[start] - 48) * ft_power(10, power);
		start++;
		power = end - start;
	}
	return (res);
}
