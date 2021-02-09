/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 10:39:05 by dboyer            #+#    #+#             */
/*   Updated: 2020/05/08 17:31:06 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_hex(long nb, char *base, char *neg)
{
	long		n;
	size_t		n_base;

	n = nb;
	if (n < 0)
	{
		n = -n - 1;
		n_base = ft_nbrlen_base(n, 16);
		ft_putnstr(neg, ft_strlen(neg) - n_base);
		base = ft_islower(base[15]) ? "fedcba9876543210" : "FEDCBA9876543210";
	}
	if (n > 15)
	{
		ft_putnbr_hex(n / 16, base, neg);
		ft_putnbr_hex(n % 16, base, neg);
	}
	else
		ft_putchar(base[n % 16]);
}
