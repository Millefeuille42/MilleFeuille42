/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_mk2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 14:06:41 by mlabouri          #+#    #+#             */
/*   Updated: 2020/06/01 17:36:26 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

inline static int	ft_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	if (power == 1)
		return (nb);
	else
		return (nb * ft_power(nb, power - 1));
}

int					atoi_mk2(const char *s, int start, int end)
{
	int res;
	int power;

	power = end - start;
	res = 0;
	while (power >= 0 && ft_isdigit(s[start]))
	{
		res = res + ((int)s[start] - 48) * ft_power(10, power);
		start++;
		power = end - start;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	char	*s;
	long	tmp;
	int		length;

	tmp = n;
	length = (n <= 0 ? 2 : 1);
	while (n && ++length)
		n /= 10;
	if (!(s = (char *)malloc(sizeof(char) * length)))
		return (NULL);
	s[--length] = '\0';
	if (tmp <= 0)
		s[0] = (char)(tmp < 0 ? '-' : '0');
	while (tmp)
	{
		s[--length] = (char)((tmp < 0 ? -tmp : tmp) % 10 + '0');
		tmp /= 10;
	}
	return (s);
}

