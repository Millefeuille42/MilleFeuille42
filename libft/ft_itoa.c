/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 16:35:53 by mlabouri          #+#    #+#             */
/*   Updated: 2019/10/09 17:18:41 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

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
	int		i;
	int		n2;
	char	*str;

	i = 1;
	n2 = n;
	while ((n / ft_power(10, i)) > 9)
		i++;
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	i = 0;
	while ((n / ft_power(10, i + 1)) > 9)
	{
		str[i] = '2';
		i++;
	}
	return (str);
}

int main()
{
	printf("%s\n", ft_itoa(25));
	return 0;
}
