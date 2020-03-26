/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 15:48:20 by mlabouri          #+#    #+#             */
/*   Updated: 2020/03/26 18:02:37 by millefeuille     ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "graphical.h"

static t_draw	def_length(t_win cub, t_ray r, double r_a)
{
	t_draw	rt;
	int		line_height;

	rt.dist = sqrt(pow(cub.conf->pos.x - r.cpos.x, 2)
			+ pow(cub.conf->pos.y - r.cpos.y, 2));

	line_height = (int)((cub.conf->res.y) / rt.dist);
	if (rt.dist == 0)
		line_height = 0;
	rt.s = -line_height / 2 + cub.conf->res.y / 2 + cub.inc_u;
	if (rt.s < 0)
		rt.s = 0;
	rt.e = line_height / 2 + cub.conf->res.y / 2 + cub.inc_d;
	if (rt.e >= cub.conf->res.y)
		rt.e = cub.conf->res.y - 1;
	return (rt);
}

t_img	image_pixel_put(int x, int y, t_img img, t_plan color)
{
	img.c_img[y * img.sl + x * (img.bpp / 8)] = (char)color.b;
	img.c_img[y * img.sl + x * (img.bpp / 8) + 1] = (char)color.g;
	img.c_img[y * img.sl + x * (img.bpp / 8) + 2] = (char)color.r;
	return (img);
}

t_img	image_pixel_put_a(int x, int y, t_img img, t_plan color)
{
	img.c_img[y * img.sl + x * (img.bpp / 8)] = (char)color.b;
	img.c_img[y * img.sl + x * (img.bpp / 8) + 1] = (char)color.g;
	img.c_img[y * img.sl + x * (img.bpp / 8) + 2] = (char)color.r;
	img.c_img[y * img.sl + x * (img.bpp / 8) + 2] = 5;
	return (img);
}

t_win			draw(t_win cub, t_ray r, int x, double r_a)
{
	int		i;
	double		dist;
	t_draw	lim;
	t_plan	col;
	t_plan g_col;

	if (x >= cub.conf->res.x)
		return (cub);
	lim = def_length(cub, r, r_a);
	dist = lim.dist;
	
	col = (t_plan){((255.0/255.0)+0.1) * (2 * (255.0/dist)),
				   ((0.0/255.0)+0.1) * (2 * (255.0/dist)),
				   ((0.0/255.0)+0.1) * (2 * (255.0/dist))};
	col.r = col.r > 255 ? 255 : col.r;
	col.g = col.g > 255 ? 255 : col.g;
	col.b = col.b > 255 ? 255 : col.b;
	col.r = col.r < 0 ? 0 : col.r;
	col.g = col.g < 0 ? 0 : col.g;
	col.b = col.b < 0 ? 20 : col.b;

			i = 0;
	while (i < (cub.conf->res.y - 1))
	{

		g_col = (t_plan){((0.0/255.0)+0.1) * (100 * ((float)i/255)),
						 ((0.0/255.0)+0.1) * (100 * ((float)i/255)),
						 ((100.0/255.0)+0.1) * (100 * ((float)i/255))};
		g_col.r = g_col.r > 255 ? 255 : g_col.r;
		g_col.g = g_col.g > 255 ? 255 : g_col.g;
		g_col.b = g_col.b > 255 ? 255 : g_col.b;
		g_col.r = g_col.r < 0 ? 0 : g_col.r;
		g_col.g = g_col.g < 0 ? 0 : g_col.g;
		g_col.b = g_col.b < 0 ? 20 : g_col.b;

		if (i < lim.s)
			image_pixel_put(x, i, cub.img, (t_plan) {125, 125, 0});
		else if (i < lim.e)
			image_pixel_put(x, i, cub.img, col);
		else
			image_pixel_put(x, i, cub.img, g_col);
		i++;
	}
	return (cub);
}
