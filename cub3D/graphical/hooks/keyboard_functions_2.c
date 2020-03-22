/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 17:19:16 by mlabouri          #+#    #+#             */
/*   Updated: 2020/03/22 12:31:41 by millefeuille     ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../graphical.h"

void 	r_left(t_win **cub)
{
	(*cub)->conf->dir_a = (*cub)->conf->dir_a - 10;
	if ((*cub)->conf->dir_a <= 0)
		(*cub)->conf->dir_a = 360 - fabs((*cub)->conf->dir_a);
}

void 	r_right(t_win **cub)
{
	(*cub)->conf->dir_a = (*cub)->conf->dir_a + 10;
	if ((*cub)->conf->dir_a >= 360)
		(*cub)->conf->dir_a = (*cub)->conf->dir_a - 360;
}

void 	r_up(t_win **cub)
{
	if ((*cub)->inc_u < 100)
		(*cub)->inc_u += 10;
	if ((*cub)->inc_d < 100)
		(*cub)->inc_d += 10;
}

void 	r_down(t_win **cub)
{
	if ((*cub)->inc_u > -100)
		(*cub)->inc_u -= 10;
	if ((*cub)->inc_d > -100)
		(*cub)->inc_d -= 10;
}