/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:48:10 by mlabouri          #+#    #+#             */
/*   Updated: 2020/02/07 10:17:28 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int nb;

	if (fd < 0)
		return ;
	nb = (int)n;
	if (nb < 0)
	{
		nb = -nb;
		ft_putchar_fd('-', 1);
	}
		if (nb > 9)
	{
		ft_putnbr_fd(nb / 10, fd);
		nb = nb % 10;
	}
	nb = nb + 48;
	write(fd, &nb, 1);
}

void	ft_putunbr(unsigned int nb)
{
	if (nb > 9)
	{
		ft_putunbr(nb / 10);
		nb = nb % 10;
	}
	nb = nb + 48;
	write(1, &nb, 1);
}
