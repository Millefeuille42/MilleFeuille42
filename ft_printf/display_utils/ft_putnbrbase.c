/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrbase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 15:19:26 by mlabouri          #+#    #+#             */
/*   Updated: 2020/02/10 10:24:15 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static	void	ft_set(unsigned int nb, int length, unsigned int baselen, char *base)
{
	int		i;
	char	n[length];

	i = length - 1;
	while (nb > baselen)
	{
		n[i] = base[(nb % baselen)];
		nb = nb / baselen;
		i--;
	}
	n[0] = base[nb];
	i = 0;
	while (i != length)
	{
		write(1, &n[i], 1);
		i++;
		g_count++;
	}
}

void			ft_putnbrbase(int n, char *base)
{
	unsigned int	baselen;
	unsigned int	nb;
	unsigned int	nb2;
	size_t			length;

	baselen = ft_strlen(base);
	nb = (unsigned int)n;
	nb2 = nb;
	length = 1;
	while (nb > baselen)
	{
		nb = nb / baselen;
		length++;
	}
	ft_set(nb2, length, baselen, base);
}
