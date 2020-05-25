/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_rendering.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 15:58:05 by mlabouri          #+#    #+#             */
/*   Updated: 2020/05/18 11:12:44 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/graphical.h"

inline static t_col	sp_text_spot(t_dvec co, t_sprite s, t_text t)
{
	t_col	color;
	double	x_hit;
	double	y_hit;

	x_hit = ((co.x - s.lim_x.x) / (s.lim_x.y - s.lim_x.x)) * t.s.x;
	y_hit = ((co.y - s.lim_y.x) / (s.lim_y.y - s.lim_y.x)) * t.s.y;
	color.b = t.i.c_img[(int)y_hit * t.i.sl + (int)x_hit * (t.i.bpp / 8)];
	color.g = t.i.c_img[(int)y_hit * t.i.sl + (int)x_hit * (t.i.bpp / 8) + 1];
	color.r = t.i.c_img[(int)y_hit * t.i.sl + (int)x_hit * (t.i.bpp / 8) + 2];
	return (color);
}

inline static t_img	sp_image_pixel_put(int x, int y, t_img img, t_col color)
{
	if (color.r || color.g || color.b)
	{
		img.c_img[y * img.sl + x * (img.bpp / 8)] = (char)color.b;
		img.c_img[y * img.sl + x * (img.bpp / 8) + 1] = (char)color.g;
		img.c_img[y * img.sl + x * (img.bpp / 8) + 2] = (char)color.r;
	}
	return (img);
}

inline static char	in_scr(t_res res, int x, int y)
{
	if (y < res.y && y >= 0 && x < res.x && x >= 0)
		return (1);
	return (0);
}


t_win				sp_draw_2(t_win cub, t_sprite s)
{
	t_col	spt;
	int		i;
	int		i2;

	i = s.lim_y.x;
	while (i < s.lim_y.y)
	{
		i2 = s.lim_x.x;
		while (i2 < s.lim_x.y)
		{
			if (in_scr(cub.conf->res, i2, i) && (s.b_dist <= cub.conf->buf[i2 +
			(i * cub.conf->res.x)] || 0 == cub.conf->buf[i2 +
			(i * cub.conf->res.x)]) && s.b_dist <= cub.conf->buf[i2])
			{
				spt = sp_text_spot((t_dvec){i2, i}, s, cub.conf->sprite_2);
				spt = shade_text(spt, s.b_dist);
				cub.img = sp_image_pixel_put(i2, i, cub.img, spt);
				if (spt.r || spt.g || spt.b)
					cub.conf->buf[i2 + (i * cub.conf->res.x)] = s.b_dist;
			}
			i2++;
		}
		i++;
	}
	return (cub);
}
t_win				sp_draw(t_win cub, t_sprite s)
{
	t_col	spt;
	int		i;
	int		i2;

	i = s.lim_y.x;
	while (i < s.lim_y.y)
	{
		i2 = s.lim_x.x;
		while (i2 < s.lim_x.y)
		{
			if (in_scr(cub.conf->res, i2, i) && (s.b_dist <= cub.conf->buf[i2 +
			(i * cub.conf->res.x)] || 0 == cub.conf->buf[i2 +
			(i * cub.conf->res.x)]) && s.b_dist <= cub.conf->buf[i2])
			{
				spt = sp_text_spot((t_dvec){i2, i}, s, cub.conf->sprite);
				spt = shade_text(spt, s.b_dist);
				cub.img = sp_image_pixel_put(i2, i, cub.img, spt);
				if (spt.r || spt.g || spt.b)
					cub.conf->buf[i2 + (i * cub.conf->res.x)] = s.b_dist;
			}
			i2++;
		}
		i++;
	}
	return (cub);
}
