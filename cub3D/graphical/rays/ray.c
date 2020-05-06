/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 14:06:41 by mlabouri          #+#    #+#             */
/*   Updated: 2020/04/30 18:34:44 by millefeui        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/graphical.h"

static	t_ray	init_ray(t_play p, double cam)
{
	t_ray r;

	r = (t_ray){};
	r.dir = (t_dvec) {p.dir.x + p.plan.x * cam, p.dir.y + p.plan.y * cam};
	r.mpos = (t_ivec) {(int)p.pos.x, (int)p.pos.y};
	r.dist = (t_dvec){(r.dir.x == 0) ? 1 : 0, (r.dir.y == 0) ? 1 : 0};
	if (r.dir.x && r.dir.y)
		r.dist = (t_dvec){fabs(1 / r.dir.x), fabs(1 / r.dir.y)};
	r.step = (t_ivec){1, 1};
	r.sdist.x = (r.mpos.x + 1.0 - p.pos.x) * r.dist.x;
	r.sdist.y = (r.mpos.y + 1.0 - p.pos.y) * r.dist.y;
	if (r.dir.x < 0)
	{
		r.step.x = -1;
		r.sdist.x = (p.pos.x - r.mpos.x) * r.dist.x;
	}
	if (r.dir.y < 0)
	{
		r.step.y = -1;
		r.sdist.y = (p.pos.y - r.mpos.y) * r.dist.y;
	}
	return (r);
}

static	t_ray	cast_ray(t_win cub, t_ray r)
{
	while (!r.hit)
	{
		if (r.sdist.x < r.sdist.y)
		{
			r.sdist.x += r.dist.x;
			r.mpos.x += r.step.x;
			r.side = 0;
		}
		else
		{
			r.sdist.y += r.dist.y;
			r.mpos.y += r.step.y;
			r.side = 1;
		}
		if (cub.conf->map[r.mpos.y][r.mpos.x] > '0')
			r.hit = 1;
	}
	return (r);
}

int				raycasting(t_win *cub)
{
	t_ray r;
	int x;
	double cam;

	init_textures(cub);
	x = 0;
	while (x < cub->conf->res.x)
	{
		cam = 2 * x / (double)cub->conf->res.x - 1;
		r = init_ray(cub->conf->play, cam);
		r = cast_ray(*cub, r);
		*cub = draw(*cub, r, x);
		x++;
	}
	minimap(*cub);
	return (0);
}
