/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 14:06:41 by mlabouri          #+#    #+#             */
/*   Updated: 2020/05/14 15:58:05 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/graphical.h"

void	left(t_win **cub)
{
	t_dvec	n_pos;
	t_dvec	dir;

	dir = (*cub)->conf->play.dir;
	rotate(&dir, 90);
	n_pos.x = (*cub)->conf->play.pos.x + dir.x / 5;
	n_pos.y = (*cub)->conf->play.pos.y + dir.y / 5;
	if ((*cub)->conf->map[(int)(n_pos.y + dir.y / 5)]
		[(int)(n_pos.x + dir.x / 5)] != '0')
		return ;
	(*cub)->conf->play.pos = n_pos;
}

void	right(t_win **cub)
{
	t_dvec	n_pos;
	t_dvec	dir;

	dir = (*cub)->conf->play.dir;
	rotate(&dir, -90);
	n_pos.x = (*cub)->conf->play.pos.x + dir.x / 5;
	n_pos.y = (*cub)->conf->play.pos.y + dir.y / 5;
	if ((*cub)->conf->map[(int)(n_pos.y + dir.y / 5)]
	[(int)(n_pos.x + dir.x / 5)] != '0')
		return ;
	(*cub)->conf->play.pos = n_pos;
}

void	up(t_win **cub)
{
	t_dvec	n_pos;
	t_dvec	dir;

	dir = (*cub)->conf->play.dir;
	n_pos.x = (*cub)->conf->play.pos.x + dir.x / 5;
	n_pos.y = (*cub)->conf->play.pos.y + dir.y / 5;
	if ((*cub)->conf->map[(int)(n_pos.y + dir.y / 2)]
		[(int)(n_pos.x + dir.x / 2)] != '0')
		return ;
	(*cub)->conf->play.pos = n_pos;
}

void	down(t_win **cub)
{
	t_dvec	n_pos;
	t_dvec	dir;

	dir = (*cub)->conf->play.dir;
	n_pos.x = (*cub)->conf->play.pos.x - dir.x / 5;
	n_pos.y = (*cub)->conf->play.pos.y - dir.y / 5;
	if ((*cub)->conf->map[(int)(n_pos.y - dir.y / 2)]
		[(int)(n_pos.x - dir.x / 2)] != '0')
		return ;
	(*cub)->conf->play.pos = n_pos;
}

void	escape(t_win **cub)
{
	mlx_destroy_image((*cub)->mlx, (*cub)->conf->no.i.v_img);
	mlx_destroy_image((*cub)->mlx, (*cub)->conf->so.i.v_img);
	mlx_destroy_image((*cub)->mlx, (*cub)->conf->we.i.v_img);
	mlx_destroy_image((*cub)->mlx, (*cub)->conf->ea.i.v_img);
	mlx_destroy_image((*cub)->mlx, (*cub)->conf->sprite.i.v_img);
	mlx_destroy_image((*cub)->mlx, (*cub)->img.v_img);
	mlx_destroy_window((*cub)->mlx, (*cub)->win);
	deinit_conf((*cub)->conf);
	exit(0);
}
