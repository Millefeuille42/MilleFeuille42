/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 14:58:24 by mlabouri          #+#    #+#             */
/*   Updated: 2020/02/12 16:48:45 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

struct s_f ft_szero(struct s_f bin)
{
	bin.dot = 0;
	bin.dotc = 0;
	bin.minus = 0;
	bin.pad = 0;
	bin.zero = 0;
	bin.zeros = 0;
	return (bin);
}
