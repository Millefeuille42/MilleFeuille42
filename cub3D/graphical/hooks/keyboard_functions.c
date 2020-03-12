/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 17:19:16 by mlabouri          #+#    #+#             */
/*   Updated: 2020/03/12 17:31:53 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../graphical.h"

void 	left(t_win **cub)
{
	(*cub)->conf->dir_a = (*cub)->conf->dir_a - 10;
	if ((*cub)->conf->dir_a <= 0)
		(*cub)->conf->dir_a = 360 - fabs((*cub)->conf->dir_a);
}

void 	right(t_win **cub)
{
	(*cub)->conf->dir_a = (*cub)->conf->dir_a + 10;
	if ((*cub)->conf->dir_a >= 360)
		(*cub)->conf->dir_a = (*cub)->conf->dir_a - 360;
}

void 	up(t_win **cub)
{
	(*cub)->conf->dir_a = (*cub)->conf->dir_a - 10;
	if ((*cub)->conf->dir_a <= 0)
		(*cub)->conf->dir_a = 360 - fabs((*cub)->conf->dir_a);
}

void 	down(t_win **cub)
{
	(*cub)->conf->dir_a = (*cub)->conf->dir_a - 10;
	if ((*cub)->conf->dir_a <= 0)
		(*cub)->conf->dir_a = 360 - fabs((*cub)->conf->dir_a);
}

void 	escape(t_win **cub)
{
	deinit_conf((*cub)->conf);
	exit(0);
}