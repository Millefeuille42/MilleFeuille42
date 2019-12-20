/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrbase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 15:19:26 by mlabouri          #+#    #+#             */
/*   Updated: 2019/12/20 16:10:05 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_

void	ft_putnbrbase(int n, char *base)
{
	size_t baselen;
	size_t i;
	long int nb;

	baselen = ft_strlen(base);
	nb = (long int)n;
	if (nb < 0)
	{
		nb = -nb;
		write(1, "-", 1);
	}
	ft_convert_base(nb, base);
}