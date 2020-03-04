/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 15:34:43 by mlabouri          #+#    #+#             */
/*   Updated: 2020/03/04 18:16:53 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


double oldTime;

#include "cub3d.h"

int worldMap[24][24]=
		{
				{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,0,0,1},
				{1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1},
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

static t_ray ft_ddir(t_ray ray)
{
	if (ray.r_d_y == 0)
		ray.d_dist_x = 0;
	else if (ray.r_d_x == 0)
		ray.d_dist_x = 1;
	else
		ray.d_dist_x = fabs(1 / ray.r_d_x);
	if (ray.r_d_x == 0)
		ray.d_dist_y = 0;
	else if (ray.r_d_y == 0)
		ray.d_dist_y = 1;
	else
		ray.d_dist_y = fabs(1 / ray.r_d_y);
	return (ray);
}

static t_rc ft_dstep(t_rc rc)
{
	if (rc.r.r_d_x < 0 && (rc.r.st_x = -1))
		rc.r.s_dist_x = (rc.p.p_x - rc.m.m_x) * rc.r.d_dist_x;
	else
	{
		rc.r.st_x = 1;
		rc.r.s_dist_x = ( rc.m.m_x + 1 - rc.p.p_x) * rc.r.d_dist_x;
	}
	if (rc.r.r_d_y < 0 && (rc.r.st_y = -1))
		rc.r.s_dist_y = (rc.p.p_y - rc.m.m_y) * rc.r.d_dist_y;
	else
	{
		rc.r.st_y = 1;
		rc.r.s_dist_y = ( rc.m.m_y + 1 - rc.p.p_y) * rc.r.d_dist_y;
	}
	return (rc);
}

static t_rc ft_dda(t_rc rc)
{
	while (rc.r.hit == 0)
	{
		//jump to next map square, OR in x-direction, OR in y-direction
		if (rc.r.s_dist_x < rc.r.s_dist_y)
		{
			rc.r.s_dist_x += rc.r.d_dist_x;
			rc.m.m_x += rc.r.st_x;
			rc.r.side = 0;
		}
		else
		{
			rc.r.s_dist_y += rc.r.d_dist_y;
			rc.m.m_y += rc.r.st_y;
			rc.r.side = 1;
		}
		
		//Check if ray has hit a wall
		if (worldMap[rc.m.m_x][rc.m.m_x] > 0)
			rc.r.hit = 1;
	}
	return (rc);
}

static void	ft_draw(t_rc rc)
{
	t_draw	draw;
	int color;

	//Calculate height of line to draw on screen
	if (rc.r.pwd != 0)
		draw.l_h = (int)(rc.conf->res.y / rc.r.pwd);
	//calculate lowest and highest pixel to fill in current stripe
	draw.dr_st = -draw.l_h / 2 + rc.conf->res.y / 2;
	if (draw.dr_st < 0)
		draw.dr_st = 0;
	draw.dr_end = draw.l_h / 2 + rc.conf->res.y / 2;
	if (draw.dr_end >= rc.conf->res.y)
		draw.dr_end = rc.conf->res.y - 1;

	//choose wall color
	color = 255;

	//give x and y sides different brightness
	if (rc.r.side == 1)
		color = color / 2;

	while (draw.dr_st != draw.dr_end)
	{
		//mlx_pixel_put(conf->mlxptr, conf->winptr, x, draw.dr_st, color);
		draw.dr_st++;
	}
}

t_rc mlx3D(t_cub *conf)
{
	t_rc rc;
	int x;

//	rc.player = conf->player;
	rc.p = (t_player) {
			.p_x = 13,
			.p_y = 13,
			.d_x = -1,
			.d_y = 0,
			.plane_x = 0,
			.plane_y = 0.66,
	};

	rc.conf = conf;
	printf("TIME,ITERATION\n");
	x = 0;

	double offset;
	double ttime;
	double fframeTime;
	double frameTime;

	while (x < conf->res.x)
	{
		offset = clock();
		fframeTime = offset / 1000;

		rc.p.camera_x = 2 * x / (double)conf->res.x - 1;
		rc.r.r_d_x = rc.p.d_x + rc.p.plane_x * rc.p.camera_x;
		rc.r.r_d_y = rc.p.d_y + rc.p.plane_y * rc.p.camera_x;

		//which box of the map we're in
		rc.m.m_x = (int)rc.p.p_x;
		rc.m.m_y = (int)rc.p.p_y;
		
		//length of ray from one x or y-side to next x or y-side
		rc.r = ft_ddir(rc.r);
		rc.r.hit = 0;
		
		//calculate step and initial sideDist
		rc = ft_dstep(rc);
		//perform DDA
		rc = ft_dda(rc);
		
		//Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
		if (rc.r.side)
			rc.r.pwd = (rc.m.m_x - rc.p.p_x + (double)(1 - rc.r.st_x) / 2) / rc.r.r_d_x;
		else
			rc.r.pwd = (rc.m.m_y - rc.p.p_y + (double)(1 - rc.r.st_y) / 2) / rc.r.r_d_y;
		ft_draw(rc);

		ttime = (double)(clock()) / 1000;
		frameTime = ((ttime - fframeTime));
		printf("%f,%i\n", frameTime, x);
		x++;
	}
	return (rc);
}