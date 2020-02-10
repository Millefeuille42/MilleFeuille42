/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_abs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 10:04:43 by mlabouri          #+#    #+#             */
/*   Updated: 2020/02/10 09:44:20 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

long int	int_abs(int nb)
{
	long int nb2;

	nb2 = (int)nb;
	ft_putchar_fd('-', 1);
	g_count++;
	return (-nb2);
}
