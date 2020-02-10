/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrbase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 15:19:26 by mlabouri          #+#    #+#             */
/*   Updated: 2020/02/10 11:24:56 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static	void	ft_set(unsigned long nb, int l, unsigned long bl, char *b)
{
	int		i;
	char	n[l];

	i = l - 1;
	while (nb > bl)
	{
		n[i] = b[(nb % bl)];
		nb = nb / bl;
		i--;
	}
	n[0] = b[nb];
	i = 0;
	while (i != l)
	{
		write(1, &n[i], 1);
		i++;
		g_count++;
	}
}

void			ft_putnbrbase(unsigned long nb, char *base)
{
	unsigned long baselen;
	unsigned long nb2;
	size_t			length;

	baselen = ft_strlen(base);
	nb2 = nb;
	length = 1;
	while (nb > baselen)
	{
		nb = nb / baselen;
		length++;
	}
	ft_set(nb2, length, baselen, base);
}
