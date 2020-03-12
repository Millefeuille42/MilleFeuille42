/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_v.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 18:52:04 by mlabouri          #+#    #+#             */
/*   Updated: 2020/03/12 19:34:07 by mlabouri         ###   ########          */
/*                                                                            */
/* ************************************************************************** */

#include "../graphical.h"

static t_ray send_ray(t_ray r, double r_angle)
{
	if ((r_angle / 100 > 269.999995 && r_angle / 100 <= 270.0000005)
		|| (r_angle / 100 > 179.999995 && r_angle / 100 <= 180.0000005)
		|| (r_angle / 100 > 89.999995 && r_angle / 100 <= 90.0000005)
		|| (r_angle / 100 > 359.999995 && r_angle / 100 <= 360.0000005)
		|| (r_angle / 100 > -1.0000005 && r_angle / 100 <= 0.0000005))
		r_angle -= 0.04;
	r.dir.x = cos((r_angle / 100) * M_PI / 180) + r.cpos.x;
	r.dir.y = sin((r_angle / 100) * M_PI / 180) + r.cpos.y;
	r.coef.x = (r.dir.y - r.cpos.y) / (r.dir.x - r.cpos.x);
	r.mpos.x = floor(r.cpos.x);
	r.mpos.y = floor(r.cpos.y);
	if ((r_angle > 0 && r_angle <= 90*100) || r_angle >= 360*100)
		r = ray_fst_quarter(r);
	else if (r_angle > 90*100 && r_angle <= 180*100)
		r = ray_scd_quarter(r);
	else if (r_angle > 180*100 && r_angle < 270*100)
		r = ray_trd_quarter(r);
	else
		r = ray_frt_quarter(r);
	return(r);
}

int raycasting(t_win cub)
{
	t_ray r;
	int x;
	double i;
	double r_angle;

	i = (cub.conf->fov / (float)cub.conf->res.x) * 100;
	r_angle = (cub.conf->dir_a - (cub.conf->fov/2)) * 100;
	x = 0;
	while ((int)r_angle <= ((int)cub.conf->dir_a + (int)cub.conf->fov / 2)*100)
	{
		r.cpos = cub.conf->pos;
		r = send_ray(r, r_angle);
		cub = draw(cub, r, x);
		x++;
		r_angle = (r_angle + i);
	}
	return (0);
}