/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 14:58:24 by mlabouri          #+#    #+#             */
/*   Updated: 2020/02/14 12:16:55 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_szero(struct s_f *bin, struct s_c *arg)
{
	bin->dot = 0;
	bin->dotc = 0;
	bin->minus = 0;
	bin->pad = 0;
	bin->zero = 0;
	bin->length = 0;
	arg->diux = 0;
	arg->p = 0;
	arg->s = 0;
	arg->ch = 0;
}
