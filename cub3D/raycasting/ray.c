/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 10:32:13 by mlabouri          #+#    #+#             */
/*   Updated: 2020/03/08 10:32:13 by mlabouri         ###   ########          */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int worldMap[24][24]=
		{
				{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
				{1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,0,0,1},
				{1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,2,1,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1},
				{1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,1,1,1,1,1,1,1,0,0,1,0,1,0,1,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,1,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,1,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
		};

static void draw(t_cub cub, t_ray r)
{
	int draw_s;
	int draw_e;
	double dist;

	dist = sqrt(((cub.pos.x - r.cpos.x) * (cub.pos.x - r.cpos.x)) + ((cub.pos.y - r.cpos.y) * (cub.pos.y - r.cpos.y)));
	int lineHeight = (int)(cub.conf->res.y / dist);
	draw_s = -lineHeight / 2 + cub.conf->res.y / 2;
	if (draw_s < 0)
		draw_s = 0;
	draw_e = lineHeight / 2 + cub.conf->res.y / 2;
	if (draw_e >= cub.conf->res.y)
		draw_e = cub.conf->res.y - 1;
	while (draw_s < draw_e)
	{
		//if (floor(dist) > 2)
		//	//mlx_pixel_put(mlxptr, winptr, x, drawStart, 255/2);
		//else
		//	mlx_pixel_put(mlxptr, winptr, x, drawStart, 255);
		draw_s++;
	}
}

static void send_ray(t_ray r)
{
	if (r.angle < 0)
		r.angle = (360*100) - fabs(r.angle);
	r.dir.x = cos((r.angle/100) * M_PI/180);
	r.dir.y = sin((r.angle/100) * M_PI/180);
	r.coef.x = (r.dir.y - r.opos.y) / (r.dir.x - r.cpos.x);
	r.coef.y = (r.dir.x - r.cpos.x) / (r.dir.y - r.opos.y);
	r.mpos.x = floor(r.cpos.x);
	r.mpos.y = floor(r.opos.y);
	while (worldMap[r.mpos.y][r.mpos.x] == 0)
	{
		r.opos.x = r.cpos.x;
		r.opos.y = r.opos.y;
		r.cpos.x = floor(r.opos.x) + 1;
		r.opos.y = ((r.cpos.x - r.opos.x) / r.coef.y) + r.opos.y;
		if (floor(r.opos.y) > floor(r.opos.y))
		{
			r.opos.y = floor(r.opos.y) + 1;
			r.cpos.x = ((r.opos.y - r.opos.y) / r.coef.x) + r.opos.x;
		}
		r.mpos.x = floor(r.cpos.x);
		r.mpos.y = floor(r.opos.y);
	}
}

int raycasting(t_cub cub)
{
	t_ray r;
	int x;
	double i;

	i = (cub.fov / (float)cub.conf->res.x) * 100;
	//mlx_clear_window(mlxptr, winptr);
	r.angle = (cub.dir_a - (cub.fov/2)) * 100;
	x = 0;
	while ((int)r.angle <= ((int)cub.dir_a + (int)cub.fov / 2)*100)
	{
		send_ray(r);
		draw(cub, r);
		x++;
		r.angle = (r.angle + i);
	}
	return (0);
}