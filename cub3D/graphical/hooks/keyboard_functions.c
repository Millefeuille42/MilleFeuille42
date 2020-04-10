/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 14:06:41 by mlabouri          #+#    #+#             */
/*   Updated: 2020/04/10 18:31:58 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../graphical.h"

void	left(t_win **cub)
{
	double		angle;
	t_dbl_co	n_pos;

	angle = (*cub)->conf->dir_a + 90;
	n_pos.x = (*cub)->conf->pos.x - (cos(angle * M_PI / 180) / 5);
	n_pos.y = (*cub)->conf->pos.y - sin(angle * M_PI / 180) / 5;
	if ((*cub)->conf->map[(int)(n_pos.y)][(int)(n_pos.x)] != '0')
		return ;
	(*cub)->conf->pos = n_pos;
}

void	right(t_win **cub)
{
	double		angle;
	t_dbl_co	n_pos;

	angle = (*cub)->conf->dir_a + 90;
	n_pos.x = (*cub)->conf->pos.x + (cos(angle * M_PI / 180) / 5);
	n_pos.y = (*cub)->conf->pos.y + sin(angle * M_PI / 180) / 5;
	if ((*cub)->conf->map[(int)(n_pos.y)][(int)(n_pos.x)] != '0')
		return ;
	(*cub)->conf->pos = n_pos;
}

void	up(t_win **cub)
{
	double		angle;
	t_dbl_co	n_pos;

	angle = (*cub)->conf->dir_a;
	n_pos.x = (*cub)->conf->pos.x + (cos(angle * M_PI / 180) / 5);
	n_pos.y = (*cub)->conf->pos.y + sin(angle * M_PI / 180) / 5;
	if ((*cub)->conf->map[(int)(n_pos.y)][(int)(n_pos.x)] != '0')
		return ;
	(*cub)->conf->pos = n_pos;
}

void	down(t_win **cub)
{
	double		angle;
	t_dbl_co	n_pos;

	angle = (*cub)->conf->dir_a;
	n_pos.x = (*cub)->conf->pos.x - (cos(angle * M_PI / 180) / 5);
	n_pos.y = (*cub)->conf->pos.y - sin(angle * M_PI / 180) / 5;
	if ((*cub)->conf->map[(int)(n_pos.y)][(int)(n_pos.x)] != '0')
		return ;
	(*cub)->conf->pos = n_pos;
}

void	escape(t_win **cub)
{
	deinit_conf((*cub)->conf);
	exit(0);
}
