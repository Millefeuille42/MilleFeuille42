/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 15:34:43 by mlabouri          #+#    #+#             */
/*   Updated: 2020/03/06 18:54:29 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <mlx.h>
#include <string.h>
#include <errno.h>
#include <math.h>
#include <time.h>

double oldTime;

//#include "cub3d.h"

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

double pos_x = 3.5;
double pos_y = 5;
double dir_x;
double dir_y;
double dir_ad = 0;

int resx = 500;
int resy = 500;

float fov = 90;
double ray_ad;
double i;

int x;

typedef struct 	s_dbl_co
{
	double		x;
	double		y;
}				t_dbl_co;

typedef struct 	s_int_co
{
	int			x;
	int			y;
}				t_int_co;

typedef struct 	s_ray
{
	t_dbl_co	dir;
	t_dbl_co	coef;
	t_dbl_co	c_pos;
	t_dbl_co	o_pos;
	t_int_co	m_pos;
}				t_ray;

int r_m_posx;
int r_m_posy;
double r_posx;
double r_posy;
double or_posx;
double or_posy;
double coef_x;
double coef_y;

int drawStart;
int drawEnd;
void *mlxptr;
void *winptr;


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
		coef_y = (dir_x - r_posx) / (dir_y - r_m_posy);

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

int pouet(int key, void *param)
{
	if (key == 124)
	{
		dir_ad = dir_ad + 16;
		if (dir_ad >= 360)
			dir_ad = dir_ad - 360;
		printf("%f\n", dir_ad);
		printf("%f\n", pos_x);
		printf("%f\n\n", pos_y);
	}

	if (key == 123)
	{
		dir_ad = dir_ad - 16;
		if (dir_ad <= 0)
			dir_ad = 360 - fabs(dir_ad);
		printf("%f\n", dir_ad);
		printf("%f\n", pos_x);
		printf("%f\n\n", pos_y);
	}

	//printf("key:%i\n", key);

	mlx_clear_window(mlxptr, winptr);


	i = (fov / (float)resx) * 100;

	ray_ad = (dir_ad - (fov/2)) * 100;

	x = 0;

//	printf("\n%f\n", dir_ad + fov/2);
	while ((int)ray_ad <= ((int)dir_ad + (int)fov / 2)*100)
	{
		//printf("\nx = %i\ni = %f\n", x, i);
		send_ray(ray_ad);
		//	draw = def_draw();
		//draw();

		double dist = sqrt(((pos_x - r_posx) * (pos_x - r_posx)) + ((pos_y - r_posy) * (pos_y - r_posy)));

		//Calculate height of line to draw on screen
		int lineHeight = (int)(resy / dist);

		//calculate lowest and highest pixel to fill in current stripe



		drawStart = -lineHeight / 2 + resy / 2;
		if(drawStart < 0)drawStart = 0;
		drawEnd = lineHeight / 2 + resy / 2;
		if(drawEnd >= resy)drawEnd = resy - 1;
		//printf("%f\n", dist);
		while (drawStart < drawEnd)
		{
			if (floor(dist) > 2)
				mlx_pixel_put(mlxptr, winptr, x, drawStart, 255/2);
			else
				mlx_pixel_put(mlxptr, winptr, x, drawStart, 255);
			drawStart++;
		}
		x++;
		ray_ad = (ray_ad + i);
	}

	return 0;
}

int main(void)
{
	mlxptr = mlx_init();
	winptr = mlx_new_window(mlxptr, resx, resy, "test");
	pouet('0', NULL);
	mlx_key_hook(winptr, &pouet, (void *)12);
	mlx_loop(mlxptr);
}