/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 14:06:41 by mlabouri          #+#    #+#             */
/*   Updated: 2020/04/30 18:34:44 by millefeui        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/graphical.h"

inline static t_draw	def_length(t_win cub, t_ray r, double r_a)
{
	t_draw	lim;
	int		line_height;

	lim.dist = sqrt(pow(cub.conf->pos.x - r.cpos.x, 2)
					+ pow(cub.conf->pos.y - r.cpos.y, 2));
	lim.dist = cos((r_a / 100 - cub.conf->dir_a) * TPI) * lim.dist;
	line_height = (int)((cub.conf->res.y) / lim.dist);
	if (lim.dist == 0)
		line_height = 0;
	lim.s = -line_height / 2 + cub.conf->res.y / 2 + cub.inc_u;
	if (lim.s < 0)
		lim.s = 0;
	lim.e = line_height / 2 + cub.conf->res.y / 2 + cub.inc_d;
	if (lim.e >= cub.conf->res.y)
		lim.e = cub.conf->res.y - 1;
	return (lim);
}

t_win					draw(t_win cub, t_ray r, int x, double r_a)
{
	int		i;
	t_draw	lim;
	t_col	col;
	t_col	g_col;

	if (x >= cub.conf->res.x)
		return (cub);
	lim = def_length(cub, r, r_a);
	i = 0;
	while (i < (cub.conf->res.y - 1))
	{
		g_col = shade(cub.conf->floor, (double)i, 0, 50);
		if (i < lim.s)
			image_pixel_put(x, i, cub.img, cub.conf->roof);
		else if (i < lim.e)
		{
			col = text_spot(r.cpos, *cub.conf->t, i, lim);
			image_pixel_put(x, i, cub.img, col);
		}
		else
			image_pixel_put(x, i, cub.img, g_col);
		i++;
	}
	return (cub);
}
