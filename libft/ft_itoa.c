/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 16:35:53 by mlabouri          #+#    #+#             */
/*   Updated: 2019/10/10 14:36:02 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static char	*ft_writenbr(long int n, char *str, int len)
{
	if (n < 0)
	{
		n = -n;
		str[0] = '-';
	}
	if (n > 9)
	{
		ft_writenbr(n / 10, str, len - 1);
		n = n % 10;
	}
	n = n + 48;
	str[len] = n;
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

char		*ft_itoa(int n)
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
	str = ft_writenbr((long int)n, str, len - 1);
	return (str);
}
