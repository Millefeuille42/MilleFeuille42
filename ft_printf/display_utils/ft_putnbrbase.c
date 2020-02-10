/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrbase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 15:19:26 by mlabouri          #+#    #+#             */
/*   Updated: 2020/02/10 09:35:54 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static	void	ft_set(long int nb, int length, int baselen, char *base)
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
	}
	g_count = g_count + i;
}

void			ft_putnbrbase(int n, char *base)
{
	int			baselen;
	long int	nb;
	long int	nb2;
	size_t		length;

	baselen = ft_strlen(base);
	nb = (size_t)n;
	if (nb < 0)
	{
		nb = -nb;
		write(1, "-", 1);
	}
	nb2 = nb;
	length = 1;
	while (nb > baselen)
	{
		nb = nb / baselen;
		length++;
	}
	ft_set(nb2, length, baselen, base);
}
