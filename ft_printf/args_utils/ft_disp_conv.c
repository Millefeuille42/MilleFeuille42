/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disp_conv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 16:58:47 by mlabouri          #+#    #+#             */
/*   Updated: 2019/12/10 17:41:39 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_disp_conv(void **arg, char bin[])
{
	char **conv;

	conv = (char **)arg;
	if (bin[4] == 'c')
		ft_putchar_fd(**conv, 1);
}

//	TODO
//		Pointer
//		Code Missing Functions
//		NO FLAG VERSION

//		&ft_putstr_fd;
//		&ft_putnbr_base;
//		&ft_putunbr;
//		&ft_putchar_fd;