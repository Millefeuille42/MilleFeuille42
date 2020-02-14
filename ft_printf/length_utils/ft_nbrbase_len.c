/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrbase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 15:19:26 by mlabouri          #+#    #+#             */
/*   Updated: 2020/02/10 11:33:49 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static	int		ft_set(unsigned long nb, int l, unsigned long bl, char *base)
{
	int		i;
	char	n[l];

	i = l - 1;
	while (nb >= bl)
	{
		n[i] = base[(nb % bl)];
		nb = nb / bl;
		i--;
	}
	n[0] = base[nb];
	i = 0;
	while (i != l)
		i++;
	return (i);
}

int				ft_nbrbase_len(unsigned long nb, char *base)
{
	unsigned long	baselen;
	unsigned long	nb2;
	size_t			length;

	baselen = ft_strlen(base);
	nb2 = nb;
	length = 1;
	while (nb >= baselen)
	{
		nb = nb / baselen;
		length++;
	}
	return (ft_set(nb2, length, baselen, base));
}
