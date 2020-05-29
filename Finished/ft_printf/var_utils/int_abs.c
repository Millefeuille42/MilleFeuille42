/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_abs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 14:06:41 by mlabouri          #+#    #+#             */
/*   Updated: 2020/05/07 12:19:22 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

long int	int_abs(int nb)
{
	long int nb2;

	nb2 = (int)nb;
	ft_putchar_fd('-', 1);
	return (-nb2);
}