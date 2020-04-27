/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 14:06:41 by mlabouri          #+#    #+#             */
/*   Updated: 2020/04/10 15:07:13 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../graphical.h"

t_ray	ray_fst_quarter(t_ray r, t_conf *conf)
{
	double hit;

	while (conf->map[r.mpos.y][r.mpos.x] == '0')
	{
		r.cpos.x += r.dir.x / 50;
		r.cpos.y += r.dir.y / 50;
		r.mpos.x = floor(r.cpos.x);
		r.mpos.y = floor(r.cpos.y);
	}
	hit = r.cpos.x - floor (r.cpos.x);
	if (hit <= 0.998 && hit >= 0.03)
	{
		conf->t = &conf->no;
		conf->t->hitpoint = 1;
	}
	else
	{
		conf->t = &conf->ea;
		conf->t->hitpoint = 0;
	}
	return (r);
}

t_ray	ray_scd_quarter(t_ray r, t_conf *conf)
{
	double hit;

	while (conf->map[r.mpos.y][r.mpos.x] == '0')
	{
		r.cpos.x += r.dir.x / 500;
		r.cpos.y += r.dir.y / 500;
		r.mpos.x = floor(r.cpos.x);
		r.mpos.y = floor(r.cpos.y);
	}
	hit = r.cpos.x - floor (r.cpos.x);
	if (hit <= 0.998 && hit >= 0.03)
	{
		conf->t = &conf->no;
		conf->t->hitpoint = 1;
	}
	else
	{
		conf->t = &conf->we;
		conf->t->hitpoint = 0;
	}
	return (r);
}

t_ray	ray_trd_quarter(t_ray r, t_conf *conf)
{
	double hit;

	while (conf->map[r.mpos.y][r.mpos.x] == '0')
	{
		r.cpos.x += r.dir.x / 500;
		r.cpos.y += r.dir.y / 500;
		r.mpos.x = floor(r.cpos.x);
		r.mpos.y = floor(r.cpos.y);
	}
	hit = r.cpos.x - floor (r.cpos.x);
	if (hit <= 0.998 && hit >= 0.03)
	{
		conf->t = &conf->so;
		conf->t->hitpoint = 1;
	}
	else
	{
		conf->t = &conf->we;
		conf->t->hitpoint = 0;
	}
	return (r);
}

t_ray	ray_frt_quarter(t_ray r, t_conf *conf)
{
	double hit;

	while (conf->map[r.mpos.y][r.mpos.x] == '0')
	{
		r.cpos.x += r.dir.x / 500;
		r.cpos.y += r.dir.y / 500;
		r.mpos.x = floor(r.cpos.x);
		r.mpos.y = floor(r.cpos.y);
	}
	hit = r.cpos.x - floor (r.cpos.x);
	if (hit <= 0.998 && hit >= 0.03)
	{
		conf->t = &conf->so;
		conf->t->hitpoint = 1;
	}
	else
	{
		conf->t = &conf->ea;
		conf->t->hitpoint = 0;
	}
	return (r);
}
