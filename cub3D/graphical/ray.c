/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 10:32:13 by mlabouri          #+#    #+#             */
/*   Updated: 2020/03/12 18:16:16 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphical.h"

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, 1);
}

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

int world2Map[24][24]=
		{
				{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
				{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
				{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
				{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
				{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
				{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
				{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
				{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
				{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
				{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
				{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
				{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
				{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
				{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
				{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
				{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
				{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
				{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
				{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
				{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
				{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
				{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
				{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
				{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2}
		};



static t_ray send_ray(t_ray r, double r_angle, t_cub cub, int x)
{
	if (r_angle / 100 > 269.999995 && r_angle / 100 <= 270.0000005)
		r_angle -= 0.04;
	if (r_angle / 100 > 179.999995 && r_angle / 100 <= 180.0000005)
		r_angle -= 0.04;
	if (r_angle / 100 > 89.999995 && r_angle / 100 <= 90.0000005)
		r_angle -= 0.04;
	if (r_angle / 100 > 359.999995 && r_angle / 100 <= 360.0000005)
		r_angle -= 0.04;
	if (r_angle / 100 > -1.0000005 && r_angle / 100 <= 0.0000005)
		r_angle -= 0.04;

	r.dir.x = cos((r_angle / 100) * M_PI / 180) + r.cpos.x;
	r.dir.y = sin((r_angle / 100) * M_PI / 180) + r.cpos.y;

	r.coef.x = (r.dir.y - r.cpos.y) / (r.dir.x - r.cpos.x);
	r.mpos.x = floor(r.cpos.x);
	r.mpos.y = floor(r.cpos.y);

	while (worldMap[r.mpos.y][r.mpos.x] == 0)
	{
		r.opos.x = r.cpos.x;
		r.opos.y = r.cpos.y;

		if ((r_angle > 0 && r_angle <= 90*100) || r_angle >= 360*100)
		{
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
		else if (r_angle > 90*100 && r_angle <= 180*100)
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
		else if (r_angle > 180*100 && r_angle < 270*100)
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
		else
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

		world2Map[r.mpos.y][r.mpos.x] = worldMap[r.mpos.y][r.mpos.x];

		//mlx_pixel_put(cub.mlx, cub.win, (int)((r.cpos.x) * 16), (int)((r.cpos.y) * 16), 16776960);
	}
	return(r);
}

int raycasting(t_win cub)
{
	t_ray r;
	int x;
	double i;
	double r_angle;

	int iii = 0;
	int iii2;

	while (iii < 24)
	{
		iii2 = 0;
		while (iii2 < 24)
		{
			world2Map[iii][iii2] = 2;
			iii2++;
		}
		iii++;
	}

	i = (cub.fov / (float)cub.conf->res.x) * 100;
	r_angle = (cub.dir_a - (cub.fov/2)) * 100;
	x = 0;
	while ((int)r_angle <= ((int)cub.dir_a + (int)cub.fov / 2)*100)
	{
		r.cpos = cub.pos;
		r = send_ray(r, r_angle, cub, x);
		cub = draw(cub, r, x);
		x++;
		r_angle = (r_angle + i);
	}
	//int ii = 23;
	//int ii2;

	world2Map[(int)cub.pos.y][(int)cub.pos.x] = 8;

	//while (ii >= 0)
	//{
	//	ii2 = 0;
	//	while (ii2 < 24)
	//	{
	//		printf("%i ", world2Map[ii][ii2]);
	//		ii2++;
	//	}
	//	printf("\n");
	//	ii--;
	//}

	return (0);
}
