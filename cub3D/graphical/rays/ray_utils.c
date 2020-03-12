/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 19:13:37 by mlabouri          #+#    #+#             */
/*   Updated: 2020/03/12 19:33:17 by mlabouri         ###   ########          */
/*                                                                            */
/* ************************************************************************** */

#include "../graphical.h"

int worldMap[24][24]=
		{
				{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
				{1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,1,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,1,0,1,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,1},
				{1,1,1,1,0,1,1,1,1,0,0,0,0,0,0,0,1,0,1,0,0,0,0,1},
				{1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,1},
				{1,1,0,0,0,0,1,0,1,0,0,0,0,0,0,0,1,0,0,0,1,0,0,1},
				{1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1},
				{1,1,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
		};

t_ray ray_fst_quarter(t_ray r)
{
	while (worldMap[r.mpos.y][r.mpos.x] == 0)
	{
		r.opos.x = r.cpos.x;
		r.opos.y = r.cpos.y;
		r.cpos.x = floor(r.opos.x) + 1;
		r.cpos.y = (r.cpos.x - r.opos.x) * r.coef.x + r.opos.y;
		if (floor(r.cpos.y) > floor(r.opos.y))
		{
			r.cpos.y = floor(r.opos.y) + 1;
			r.cpos.x = ((r.cpos.y - r.opos.y) / r.coef.x) + r.opos.x;
		}
		if (floor(r.cpos.x) > 23)
			r.cpos.x = 23;
		if (floor(r.cpos.y) > 23)
			r.cpos.y = 23;
		if (floor(r.cpos.x) < 0)
			r.cpos.x = 0;
		if (floor(r.cpos.y) < 0)
			r.cpos.y = 0;
		r.mpos.x = floor(r.cpos.x);
		r.mpos.y = floor(r.cpos.y);
	}
	return (r);
}

t_ray ray_scd_quarter(t_ray r)
{
	while (worldMap[r.mpos.y][r.mpos.x] == 0)
	{
		r.cpos.x = ceil(r.opos.x) - 1;
		r.cpos.y = (r.opos.x - r.cpos.x) * (-r.coef.x) + r.opos.y;
		if (floor(r.cpos.y) > floor(r.opos.y))
		{
			r.cpos.y = floor(r.opos.y) + 1;
			r.cpos.x = ((r.cpos.y - r.opos.y) / r.coef.x) + r.opos.x;
		}
		if (ceil(r.cpos.x) > 23)
			r.cpos.x = 23;
		if (floor(r.cpos.y) > 23)
			r.cpos.y = 23;
		if (ceil(r.cpos.x) < 0)
			r.cpos.x = 0;
		if (floor(r.cpos.y) < 0)
			r.cpos.y = 0;

		r.mpos.x = ceil(r.cpos.x);
		r.mpos.y = floor(r.cpos.y);
	}
	return (r);
}

t_ray ray_trd_quarter(t_ray r)
{
	while (worldMap[r.mpos.y][r.mpos.x] == 0)
	{
		r.cpos.x = ceil(r.opos.x) - 1;
		r.cpos.y = (r.opos.x - r.cpos.x) * -(r.coef.x) + r.opos.y;
		if (ceil(r.cpos.y) < ceil(r.opos.y))
		{
			r.cpos.y = ceil(r.opos.y) - 1;
			r.cpos.x = -((r.opos.y - r.cpos.y) / r.coef.x) + r.opos.x;
		}
		if (ceil(r.cpos.x) > 23)
			r.cpos.x = 23;
		if (ceil(r.cpos.y) > 23)
			r.cpos.y = 23;
		if (ceil(r.cpos.x) < 0)
			r.cpos.x = 0;
		if (ceil(r.cpos.y) < 0)
			r.cpos.y = 0;

		r.mpos.x = ceil(r.cpos.x);
		r.mpos.y = ceil(r.cpos.y);
	}
	return (r);
}

t_ray ray_frt_quarter(t_ray r)
{
	while (worldMap[r.mpos.y][r.mpos.x] == 0)
	{
		r.cpos.x = floor(r.opos.x) + 1;
		r.cpos.y = (r.cpos.x - r.opos.x) * r.coef.x + r.cpos.y;
		if (ceil(r.cpos.y) < ceil(r.opos.y))
		{
			r.cpos.y = ceil(r.opos.y) - 1;
			r.cpos.x = -((r.opos.y - r.cpos.y) / r.coef.x) + r.opos.x;
		}
		if (floor(r.cpos.x) > 23)
			r.cpos.x = 23;
		if (ceil(r.cpos.y) > 23)
			r.cpos.y = 23;
		if (floor(r.cpos.x) < 0)
			r.cpos.x = 0;
		if (ceil(r.cpos.y) < 0)
			r.cpos.y = 0;

		r.mpos.x = floor(r.cpos.x);
		r.mpos.y = ceil(r.cpos.y);
	}
	return (r);
}