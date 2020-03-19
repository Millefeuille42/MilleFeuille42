/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 17:19:16 by mlabouri          #+#    #+#             */
/*   Updated: 2020/03/19 10:55:10 by millefeuille     ###   ########lyon.fr   */
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
	double angle;

	angle = (*cub)->conf->dir_a;

	(*cub)->conf->pos.x += (cos(angle * M_PI / 180) / 5);
	(*cub)->conf->pos.y += sin(angle * M_PI / 180) / 5;
}

void 	down(t_win **cub)
{
	double angle;

	angle = (*cub)->conf->dir_a;

	(*cub)->conf->pos.x -= (cos(angle * M_PI / 180) / 5);
	(*cub)->conf->pos.y -= sin(angle * M_PI / 180) / 5;
}

void 	escape(t_win **cub)
{
	deinit_conf((*cub)->conf);
	exit(0);
}