/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_val_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 14:33:25 by mlabouri          #+#    #+#             */
/*   Updated: 2019/11/28 15:34:46 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int val_minus(const char *s, size_t i)
{
	return (2);
}

int val_zero(const char *s, size_t i)
{
	return (2);
}

int val_dot(const char *s, size_t i)
{
	return (2);
}

int val_glob(const char *s, size_t i)
{
	return (2);
}

int ft_val_flags(const char *s, size_t i, char flag)
{
	char flags[4];
	int (*func[4])(const char *, size_t);
	int i2;

	i2 = 0;
	flags[0] = '-';
	flags[1] = '0';
	flags[2] = '.';
	flags[3] = '*';
	func[0] = &val_minus;
	func[1] = &val_zero;
	func[2] = &val_dot;
	func[3] = &val_glob;
	while (flag != flags[i2])
		i2++;
	return ((func)[i2](s, i));
}