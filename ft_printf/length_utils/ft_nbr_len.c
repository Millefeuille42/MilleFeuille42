/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 10:30:08 by mlabouri          #+#    #+#             */
/*   Updated: 2020/03/12 18:50:35 by mlabouri         ###   ########          */
/*                                                                            */
/* ************************************************************************** */

int		ft_nbr_len(int n)
{
	long int	nb;
	int			length;

	length = 1;
	nb = (long int)n;
	if (nb < 0)
	{
		nb = -nb;
		length++;
	}
	while (nb >= 10)
	{
		nb = nb / 10;
		length++;
	}
	return (length);
}

int		ft_unbr_len(unsigned int nb)
{
	int	length;

	length = 1;
	while (nb >= 10)
	{
		nb = nb / 10;
		length++;
	}
	return (length);
}
