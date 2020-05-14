/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 14:06:41 by mlabouri          #+#    #+#             */
/*   Updated: 2020/05/14 15:58:05 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/graphical.h"

inline static t_draw	def_length(t_win cub, t_ray r)
{
	t_draw	lim;
	int		line_height;

	if (!r.side)
		lim.dist = (r.mpos.x - cub.conf->play.pos.x
				+ (double)(1 - r.step.x) / 2) / r.dir.x;
	else
		lim.dist = (r.mpos.y - cub.conf->play.pos.y
					+ (double)(1 - r.step.y) / 2) / r.dir.y;
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

t_win					draw(t_win cub, t_ray r, int x)
{
	int		i;
	t_draw	lim;
	t_col	col;
	t_col	g_col;

	if (x >= cub.conf->res.x)
		return (cub);
	lim = def_length(cub, r);
	i = 0;
	while (i < (cub.conf->res.y - 1))
	{
		g_col = shade(cub.conf->floor, (double)i - cub.inc_d, 0, 50);
		if (i < lim.s)
			image_pixel_put(x, i, cub.img, cub.conf->roof);
		else if (i < lim.e)
		{
			col = text_spot(r, *cub.conf->t, i, lim);
			//col = shade(col, lim.dist, 1, 1);
			image_pixel_put(x, i, cub.img, col);
		}
		else
			image_pixel_put(x, i, cub.img, g_col);
		i++;
	}
	return (cub);
}
