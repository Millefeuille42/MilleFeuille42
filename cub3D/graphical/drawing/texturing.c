/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texturing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 16:29:23 by mlabouri          #+#    #+#             */
/*   Updated: 2020/04/13 16:39:46 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/graphical.h"

void	init_textures(t_win *cub)
{
	t_text *t;

	t = &cub->conf->no;
	t->i.v_img = mlx_xpm_file_to_image(cub->mlx, t->path, &t->s.x, &t->s.y);
	t->i.c_img = mlx_get_data_addr(t->i.v_img, &t->i.bpp, &t->i.sl, &t->i.e);
	t = &cub->conf->so;
	t->i.v_img = mlx_xpm_file_to_image(cub->mlx, t->path, &t->s.x, &t->s.y);
	t->i.c_img = mlx_get_data_addr(t->i.v_img, &t->i.bpp, &t->i.sl, &t->i.e);
	t = &cub->conf->ea;
	t->i.v_img = mlx_xpm_file_to_image(cub->mlx, t->path, &t->s.x, &t->s.y);
	t->i.c_img = mlx_get_data_addr(t->i.v_img, &t->i.bpp, &t->i.sl, &t->i.e);
	t = &cub->conf->we;
	t->i.v_img = mlx_xpm_file_to_image(cub->mlx, t->path, &t->s.x, &t->s.y);
	t->i.c_img = mlx_get_data_addr(t->i.v_img, &t->i.bpp, &t->i.sl, &t->i.e);
	t = &cub->conf->sprite;
	t->i.v_img = mlx_xpm_file_to_image(cub->mlx, t->path, &t->s.x, &t->s.y);
	t->i.c_img = mlx_get_data_addr(t->i.v_img, &t->i.bpp, &t->i.sl, &t->i.e);
}

t_col	text_spot(t_dbl_co hit, t_text t, double y, t_draw lim)
{
	t_col	color;
	int		x_hit;
	double	y_hit;

	if (t.hitpoint)
		x_hit = floor((hit.x - floor(hit.x)) * t.s.x);
	else
		x_hit = floor((hit.y - floor(hit.y)) * t.s.y);
	y_hit = ((y - lim.s) / (lim.e - lim.s)) * t.s.y;
	color.b = t.i.c_img[(int)y_hit * t.i.sl + x_hit * (t.i.bpp / 8)];
	color.g = t.i.c_img[(int)y_hit * t.i.sl + x_hit * (t.i.bpp / 8) + 1];
	color.r = t.i.c_img[(int)y_hit * t.i.sl + x_hit * (t.i.bpp / 8) + 2];
	return (color);
}
