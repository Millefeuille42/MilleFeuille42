/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_calculations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 15:58:05 by mlabouri          #+#    #+#             */
/*   Updated: 2020/05/14 15:58:05 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/graphical.h"

inline static void	sprites_dist(t_win cub)
{
	int			i;
	t_sprite	*s;
	t_play		p;

	p = cub.conf->play;
	i = 0;
	while (!cub.conf->sp_list[i].last)
	{
		s = &cub.conf->sp_list[i];
		s->c_pos.x = s->pos.x - p.pos.x + 0.5;
		s->c_pos.y = s->pos.y - p.pos.y + 0.5;
		s->b_dist = (pow(p.pos.x - s->pos.x, 2)
				+ pow(p.pos.y - s->pos.y, 2));
		s->dist = (pow(p.pos.x - s->c_pos.x, 2)
				+ pow(p.pos.y - s->c_pos.y, 2));
		i++;
	}
}

inline static void	sort_sprites(t_sprite *sprites)
{
	int			i;
	int			i2;
	t_sprite	temp;

	i2 = 0;
	i = 1;
	while (!sprites[i2 + 1].last)
	{
		while (!sprites[i].last)
		{
			if (sprites[i2].dist <= sprites[i].dist)
				i++;
			else
			{
				temp = sprites[i];
				sprites[i] = sprites[i2];
				sprites[i2] = temp;
				i = i2 + 1;
			}
		}
		i2++;
		i = i2 + 1;
	}
}

inline static void	sprites_screen(t_play p, t_sprite *s, t_win cub)
{
	double	inv;
	t_dvec	trans;
	int		screen;
	int		factor;

	inv = 1.0 / (p.plan.x * p.dir.y - p.plan.y * p.dir.x);
	trans.x = inv * (p.dir.y * s->c_pos.x - p.dir.x * s->c_pos.y);
	trans.y = inv * (-p.plan.y * s->c_pos.x + p.plan.x * s->c_pos.y);
	screen = (int)((int)(cub.conf->res.x / 2) * (1 + trans.x / trans.y));
	factor = abs((int)(cub.conf->res.y / trans.y));
	s->lim_y.x = -factor / 2 + cub.conf->res.y / 2 + cub.inc_u;
	s->lim_y.y = factor / 2 + cub.conf->res.y / 2 + cub.inc_d;
	s->lim_x.x = -factor / 2 + screen;
	s->lim_x.y = factor / 2 + screen;
}

t_win				sprites_calculations(t_win cub)
{
	int i;

	i = 0;
	sprites_dist(cub);
	sort_sprites(cub.conf->sp_list);
	while (!cub.conf->sp_list[i].last)
	{
		if (cub.conf->sp_list[i].hit)
		{
			sprites_screen(cub.conf->play, &cub.conf->sp_list[i], cub);
			cub = sp_draw(cub, cub.conf->sp_list[i]);
		}
		cub.conf->sp_list[i].hit = 0;
		i++;
	}
	return (cub);
}
