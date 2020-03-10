/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 10:30:08 by mlabouri          #+#    #+#             */
/*   Updated: 2020/03/10 08:34:43 by mlabouri         ###   ########          */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static long		ft_special(unsigned long int n, char flag)
{
	if (flag)
		return (2147483648);
	return ((long)(int)n);
}

void			ft_putnbr_fd(unsigned long int n, int fd, char flag)
{
	long int	nb;

	if (fd < 0)
		return ;
	nb = (int)n;
	if ((int)n == INT_MIN)
		nb = ft_special(n, flag);
	if (nb < 0)
	{
		nb = -nb;
		ft_putchar_fd('-', 1);
	}
	if (nb > 9)
	{
		ft_putnbr_fd(nb / 10, fd, 0);
		nb = nb % 10;
	}
	nb = nb + 48;
	write(fd, &nb, 1);
	g_count++;
}

void			ft_putunbr(unsigned int nb)
{
	if (nb > 9)
	{
		ft_putunbr(nb / 10);
		nb = nb % 10;
	}
	nb = nb + 48;
	write(1, &nb, 1);
	g_count++;
}
