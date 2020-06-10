/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:01:56 by dboyer            #+#    #+#             */
/*   Updated: 2020/05/08 17:31:06 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_size(unsigned int n)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	while (n >= 1 && ++i)
		n = n / 10;
	return (i);
}

int		ft_power(int n, int exp)
{
	if (exp == 0)
		return (1);
	else if (exp == 1)
		return (n);
	return (ft_power(n * 10, exp - 1));
}

char	*ft_itoa(int n)
{
	int				n_size;
	char			*result;
	int				buffer;
	int				k;
	unsigned int	nb;

	nb = ft_abs(n);
	k = n < 0 ? 1 : 0;
	n_size = get_size(nb);
	n_size = n < 0 ? n_size + 1 : n_size;
	if (!(result = (char *)malloc((n_size + 1) * sizeof(char))))
		return (NULL);
	n_size = n < 0 ? ft_power(10, n_size - 2) : ft_power(10, n_size - 1);
	result[0] = n < 0 ? '-' : result[0];
	while (n_size >= 1)
	{
		buffer = nb / n_size % 10;
		result[k++] = buffer + '0';
		n_size /= 10;
	}
	result[k] = 0;
	return (result);
}
