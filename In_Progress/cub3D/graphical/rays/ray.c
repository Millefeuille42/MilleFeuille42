/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 14:06:41 by mlabouri          #+#    #+#             */
/*   Updated: 2020/05/18 11:12:44 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/graphical.h"

inline static t_ray	init_ray(t_play p, double cam)
{
	t_ray r;

	r = (t_ray){.origin = p.pos};
	r.dir = (t_dvec) {p.dir.x + p.plan.x * cam, p.dir.y + p.plan.y * cam};
	r.mpos = (t_ivec) {(int)p.pos.x, (int)p.pos.y};
	r.dist = (t_dvec){(r.dir.x == 0) ? 1 : 0, (r.dir.y == 0) ? 1 : 0};
	if (r.dir.x && r.dir.y)
		r.dist = (t_dvec){fabs(1 / r.dir.x), fabs(1 / r.dir.y)};
	r.step = (t_ivec){1, 1};
	r.sdist.x = (r.mpos.x + 1.0 - p.pos.x) * r.dist.x;
	r.sdist.y = (r.mpos.y + 1.0 - p.pos.y) * r.dist.y;
	if (r.dir.x < 0 && (r.step.x = -1))
		r.sdist.x = (p.pos.x - r.mpos.x) * r.dist.x;
	if (r.dir.y < 0 && (r.step.y = -1))
		r.sdist.y = (p.pos.y - r.mpos.y) * r.dist.y;
	return (r);
}

inline static void	def_text(t_win *cub, t_ray r)
{
	if (r.side && r.step.y == 1)
		cub->conf->t = &cub->conf->no;
	else if (r.side && r.step.y == -1)
		cub->conf->t = &cub->conf->so;
	else if (!r.side && r.step.x == 1)
		cub->conf->t = &cub->conf->ea;
	else
		cub->conf->t = &cub->conf->we;
}

inline static t_ray	cast_ray(t_win *cub, t_ray r)
{
	while (!r.hit)
	{
		if (r.sdist.x < r.sdist.y && !(r.side = 0))
		{
			r.sdist.x += r.dist.x;
			r.mpos.x += r.step.x;
		}
		else
		{
			r.sdist.y += r.dist.y;
			r.mpos.y += r.step.y;
			r.side = 1;
		}
		if (cub->conf->map[r.mpos.y][r.mpos.x] == '1')
			r.hit = 1;
		else if (cub->conf->map[r.mpos.y][r.mpos.x] == '2' ||
		cub->conf->map[r.mpos.y][r.mpos.x] == '3')
			tag_sprite(r.mpos, cub->conf->sp_list,
					cub->conf->map[r.mpos.y][r.mpos.x]);
	}
	def_text(cub, r);
	return (r);
}

int					raycasting(t_win *cub)
{
	t_ray	r;
	int		x;
	double	cam;
	int		y;

	y = -1;
	x = 0;
	while (x < cub->conf->res.x)
	{
		cam = 2 * x / (double)cub->conf->res.x - 1;
		r = init_ray(cub->conf->play, cam);
		r = cast_ray(cub, r);
		*cub = draw(*cub, r, x);
		x++;
	}
	*cub = sprites_calculations(*cub);
	reset_buffer(cub);
	minimap(*cub);
	return (0);
}
