/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 14:06:41 by mlabouri          #+#    #+#             */
/*   Updated: 2020/05/18 11:12:44 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/graphical.h"

inline static t_draw	def_length(t_win cub, t_ray r, int x)
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
	cub.conf->buf[x] = (pow(cub.conf->play.pos.x - r.mpos.x, 2)
			+ pow(cub.conf->play.pos.y - r.mpos.y, 2));
	return (lim);
}

inline static t_win		draw_line(t_win c, t_ray r, int x, t_draw lim)
{
	int		i[2];
	t_col	col;
	t_col	f_col;
	t_col	c_col;

	i[0] = 0;
	i[1] = c.conf->res.y + 100;
	while (i[0] < (c.conf->res.y - 1))
	{
		f_col = shade_plane(c.conf->floor, (double)i[0], 50, c.conf->res.y);
		c_col = shade_plane(c.conf->roof, (double)i[1], 50, c.conf->res.y);
		if (i[0] < lim.s)
			image_pixel_put(x, i[0], c.img, c_col);
		else if (i[0] < lim.e)
		{
			col = text_spot(r, *c.conf->t, i[0], lim);
			col = shade_text(col, lim.dist);
			image_pixel_put(x, i[0], c.img, col);
		}
		else
			image_pixel_put(x, i[0], c.img, f_col);
		i[0]++;
		i[1]--;
	}
	return (c);
}

t_win					draw(t_win cub, t_ray r, int x)
{
	t_draw	lim;

	lim = def_length(cub, r, x);
	cub = draw_line(cub, r, x, lim);
	return (cub);
}
