/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_val_tree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 16:13:55 by mlabouri          #+#    #+#             */
/*   Updated: 2020/01/29 14:38:19 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trees.h"

static	int		itoa_mk2(const char *s, int start, int end)
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

int				 val_minus(const char *s, size_t i)
{
	//if (ok) {return ('-' + 100)}
	//else {return '-'}
	return (2);
}

int val_zero(const char *s, size_t i)
{
	int	start;
	int	end;

	start = 0;
	end = 0;
	while (ft_isdigit(s[i]))
	{
		if (start == 0)
			start = i;
		else
			end = i;
		i++;
	}
	if (start == 0)
		return (0);
	if (end == 0)
		return (s[start]);
	return (itoa_mk2(s, start, end));
}

int val_dot(const char *s, size_t i)
{
	//if (ok) {return ('.' + 100)}
	//else {return '.'}
	return (2);
}

int val_42(const char *s, size_t i)
{
	//if (ok) {return ('*' + 100)}
	//else {return '*'}
	return (2);
}