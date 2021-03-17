/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 14:06:41 by mlabouri          #+#    #+#             */
/*   Updated: 2020/05/07 12:19:22 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/commons.h"

static char	*ft_write_nbr(long int n, char *str, int len)
{
	if (n < 0)
	{
		n = -n;
		str[0] = '-';
	}
	if (n > 9)
	{
		ft_write_nbr(n / 10, str, len - 1);
		n = n % 10;
	}
	n = n + 48;
	str[len] = (char)n;
	return (str);
}

static int	ft_power(int nb, int power)
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

char	*ft_itoa(int n)
{
	int			len;
	long int	n2;
	char		*str;

	n2 = (long int)n;
	if (n < 0)
		n2 = -n2;
	len = 1;
	while ((n2 / ft_power(10, len - 1)) > 9)
		len++;
	if (n < 0)
		len++;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	str = ft_write_nbr((long int)n, str, len - 1);
	return (str);
}
