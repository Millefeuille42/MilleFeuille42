/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 10:30:08 by mlabouri          #+#    #+#             */
/*   Updated: 2020/03/08 10:30:08 by mlabouri         ###   ########          */
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

//double pos_x = 3.5;
//double pos_y = 5;
//double dir_x;
//double dir_y;
//double dir_ad = 0;
//
//int resx = 500;
//int resy = 500;
//
//float fov = 90;
//double ray_ad;
//double i;
//
//int x;


//int r_m_posx;
//int r_m_posy;
//double r_posx;
//double r_posy;
//double or_posx;
//double or_posy;
//double coef_x;
//double coef_y;
//
//int drawStart;
//int drawEnd;
//void *mlxptr;
//void *winptr;

/*
char send_ray(double ray_a)
{
	if (ray_a < 0)
		ray_a = (360*100) - fabs(ray_a);
	dir_x = cos((ray_a/100) * M_PI/180);
	dir_y = sin((ray_a/100) * M_PI/180);

	coef_x = (dir_y - pos_y) / (dir_x - pos_x);
	coef_y = (dir_x - pos_x) / (dir_y - pos_y);

	if (dir_x > dir_y)
	{
		r_posy = floor(pos_y) + 1;
		r_posx = ((r_posy - pos_y) / coef_x) + pos_x;
	}
	else
	{
		r_posx = floor(pos_x) + 1;
		r_posy = ((r_posx - pos_x) / coef_y) + pos_y;
	}
	r_m_posx = floor(r_posx);
	r_m_posy = floor(r_posy);

	while (worldMap[r_m_posy][r_m_posx] == 0)
	{
		or_posx = r_posx;
		or_posy = r_posy;

		coef_x = (dir_y - r_posy) / (dir_x - r_posx);
		coef_y = (dir_x - r_posx) / (dir_y - r_posy);

		r_posx = floor(or_posx) + 1;
		r_posy = ((r_posx - or_posx) / coef_y) + or_posy;

		if (floor(r_posy) > floor(or_posy))
		{
			r_posy = floor(or_posy) + 1;
			r_posx = ((r_posy - or_posy) / coef_x) + or_posx;
		}
		r_m_posx = floor(r_posx);
		r_m_posy = floor(r_posy);
	}
	//printf("Pos = %i,%i wall = %i\n", r_m_posx,r_m_posy, worldMap[r_m_posy][r_m_posx]);
	//printf("ray_angle = %f\nr_posx = %f\nr_posy = %f\n", ray_a/100, r_posx, r_posy);
	return (0);
}
*/
char opti_send_ray(t_ray r)
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
	return (0);
}

//int key_hook(int key, void *param)
//{
//	if (key == 124)
//	{
//		dir_ad = dir_ad + 16;
//		if (dir_ad >= 360)
//			dir_ad = dir_ad - 360;
//		//printf("%f\n", dir_ad);
//		//printf("%f\n", pos_x);
//		//printf("%f\n\n", pos_y);
//	}
//	if (key == 123)
//	{
//		dir_ad = dir_ad - 16;
//		if (dir_ad <= 0)
//			dir_ad = 360 - fabs(dir_ad);
//		//printf("%f\n", dir_ad);
//		//printf("%f\n", pos_x);
//		//printf("%f\n\n", pos_y);
//	}
//	return (0);
//}

//int pouet(int key, t_conf conf)
//{
//	t_ray r;
//
//	//printf("key:%i\n", key);
//	//mlx_clear_window(mlxptr, winptr);
//	i = (fov / (float)resx) * 100;
//	ray_ad = (dir_ad - (fov/2)) * 100;
//	x = 0;
// 	printf("\n%f\n", dir_ad + fov/2);
//	while ((int)ray_ad <= ((int)dir_ad + (int)fov / 2)*100)
//	{
//		//printf("\nx = %i\ni = %f\n", x, i);
//		send_ray(ray_ad);
//		//	draw = def_draw();
//		//draw();
//
//		double dist = sqrt(((pos_x - r_posx) * (pos_x - r_posx)) + ((pos_y - r_posy) * (pos_y - r_posy)));
//
//		//Calculate height of line to draw on screen
//		int lineHeight = (int)(resy / dist);
//
//		//calculate lowest and highest pixel to fill in current stripe
//
//
//
//		drawStart = -lineHeight / 2 + resy / 2;
//		if(drawStart < 0)drawStart = 0;
//		drawEnd = lineHeight / 2 + resy / 2;
//		if(drawEnd >= resy)drawEnd = resy - 1;
//		//printf("%f\n", dist);
//		while (drawStart < drawEnd)
//		{
//			//if (floor(dist) > 2)
//			//	//mlx_pixel_put(mlxptr, winptr, x, drawStart, 255/2);
//			//else
//			//	mlx_pixel_put(mlxptr, winptr, x, drawStart, 255);
//			drawStart++;
//		}
//		x++;
//		ray_ad = (ray_ad + i);
//	}
//
//	return 0;
//}

void draw(t_cub cub, t_ray r)
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

int opti_pouet(t_cub cub)
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
		opti_send_ray(r);
		draw(cub, r);
		x++;
		r.angle = (r.angle + i);
	}
	return 0;
}

int main(void)
{
	t_cub cub;

	cub = (t_cub) {};
	//mlxptr = mlx_init();
	//winptr = mlx_new_window(mlxptr, resx, resy, "test");
	opti_pouet(cub);
	//mlx_key_hook(winptr, &pouet, (void *)12);
	//mlx_loop(mlxptr);
}