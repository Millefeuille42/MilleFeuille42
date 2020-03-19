/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 15:48:20 by mlabouri          #+#    #+#             */
/*   Updated: 2020/03/12 16:19:44 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphical.h"

static t_draw	def_length(t_win cub, t_ray r)
{
	t_draw	rt;
	int		line_height;

	rt.dist = sqrt(pow(cub.conf->pos.x - r.cpos.x, 2)
			+ pow(cub.conf->pos.y - r.cpos.y, 2));
	line_height = (int)(cub.conf->res.y / rt.dist);
	if (rt.dist == 0)
		line_height = 0;
	rt.s = -line_height / 2 + cub.conf->res.y / 2;
	if (rt.s < 0)
		rt.s = 0;
	rt.e = line_height / 2 + cub.conf->res.y / 2;
	if (rt.e >= cub.conf->res.y)
		rt.e = cub.conf->res.y - 1;
	return (rt);
}

static t_img	image_pixel_put(int x, int y, t_img img, t_plan color)
{
	img.c_img[y * img.sl + x * (img.bpp / 8)] = (char)color.b;
	img.c_img[y * img.sl + x * (img.bpp / 8) + 1] = (char)color.g;
	img.c_img[y * img.sl + x * (img.bpp / 8) + 2] = (char)color.r;
	return (img);
}

t_win			draw(t_win cub, t_ray r, int x)
{
	int		i;
	int		dist;
	t_draw	lim;
	t_plan	col;

	if (x >= cub.conf->res.x)
		return (cub);
	lim = def_length(cub, r);
	dist = (int)floor(lim.dist);
	if (dist < 1)
		col = (t_plan){255, 255, 255};
	else
		col = (t_plan){255 / dist, 255 / dist, 255};
	i = 0;
	while (i < (cub.conf->res.y - 1))
	{
		if (i < lim.s)
			image_pixel_put(x, i, cub.img,
					(t_plan) {125, 125, 0});
		else if (i < lim.e)
			image_pixel_put(x, i, cub.img, col);
		else
			image_pixel_put(x, i, cub.img,
					(t_plan) {0, 0, 125});
		i++;
	}
	return (cub);
}
