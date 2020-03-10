/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 10:32:13 by mlabouri          #+#    #+#             */
/*   Updated: 2020/03/10 17:12:19 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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


void draw_minimap(t_cub cub)
{
	int ii = 0;
	int ii2;
	int x;
	int y;
	int rx = 0;
	int ry;

	y = 0;
	while (ii < 24)
	{
		ii2 = 0;
		x = 0;
		while (ii2 < 24)
		{
			rx = x;
			while (rx < x + 16)
			{
				ry = y;
				while (ry < y + 16)
				{
					if (worldMap[ii][ii2] == 1)
						mlx_pixel_put(cub.mlx, cub.win, rx, ry, 16711680);
					else
						mlx_pixel_put(cub.mlx, cub.win, rx, ry, 0);
					ry++;
				}
				rx++;
			}
			x+=16;
			ii2++;
		}
		y+=16;
		ii++;
	}

	x = (int)cub.pos.x * 16;
	y = (int)cub.pos.y * 16;

	rx = x;
	while (rx < x + 16)
	{
		ry = y;
		while (ry < y + 16)
		{
			mlx_pixel_put(cub.mlx, cub.win, rx, ry, 16776960);
			ry++;
		}
		rx++;
	}
}

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

static void draw(t_cub cub, t_ray r, int x)
{
	int draw_s;
	int draw_e;
	double dist;

//	printf("%f || %f\n", r.cpos.x, r.cpos.y);
	dist = sqrt(pow(cub.pos.x - r.cpos.x, 2) + pow(cub.pos.y - r.cpos.y, 2));
//	printf("dist:%f\n\n", dist);
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
			//mlx_pixel_put(cub.mlx, cub.win, x, draw_s, 255/2);
		//else
			//mlx_pixel_put(cub.mlx, cub.win, x, draw_s, 255);
		draw_s++;
	}
}

static t_ray send_ray(t_ray r, double r_angle, t_cub cub)
{
	r.dir.x = cos((r_angle / 100) * M_PI / 180) + r.cpos.x;
	r.dir.y = sin((r_angle / 100) * M_PI / 180) + r.cpos.y;

	r.coef.x = (r.dir.y - r.cpos.y) / (r.dir.x - r.cpos.x);
//	r.coef.y = (r.dir.x - r.cpos.x) / (r.dir.y - r.cpos.y);
	r.mpos.x = floor(r.cpos.x);
	r.mpos.y = floor(r.cpos.y);
	//printf("coefx:%f\n", r.coef.x);
	//printf("r_angle:%f\n", r_angle);
	printf("diry:%f\n", r.dir.y);
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
		}
		else if (r_angle > 90*100 && r_angle <= 180*100)
		{
			r.cpos.x = ceil(r.opos.x) - 1;
			r.cpos.y = (r.cpos.x - r.opos.x) * r.coef.x + r.opos.y;
			if (floor(r.cpos.y) > floor(r.opos.y))
			{
				r.cpos.y = floor(r.opos.y) + 1;
				r.cpos.x = ((r.cpos.y - r.opos.y) / r.coef.x) + r.opos.x;
			}
		}
		else if (r_angle > 180*100 && r_angle <= 270*100)
		{
			r.cpos.x = ceil(r.opos.x) - 1;
			r.cpos.y = (r.cpos.x - r.opos.x) * r.coef.x + r.opos.y;
			if (floor(r.cpos.y) < floor(r.opos.y))
			{
				r.cpos.y = ceil(r.opos.y) - 1;
				r.cpos.x = ((r.cpos.y - r.opos.y) / r.coef.x) + r.opos.x;
			}
		}
		else
		{
			r.cpos.x = floor(r.opos.x) + 1;
			r.cpos.y = (r.cpos.x - r.opos.x) * r.coef.x + r.cpos.y;
			printf("%f || %f\n",floor(r.cpos.y), floor(r.opos.y));
			if (floor(r.cpos.y) < floor(r.opos.y))
			{
				r.cpos.y = ceil(r.opos.y) - 1;
				r.cpos.x = ((r.cpos.y - r.opos.y) / r.coef.x) + r.opos.x;
			}
		}

		if (floor(r.cpos.x) > 23)
			r.cpos.x = 23;
		if (floor(r.cpos.y) > 23)
			r.cpos.y = 23;
		if (floor(r.cpos.x) < 0)
			r.cpos.x = 0;
		if (floor(r.cpos.y) < 0)
			r.cpos.y = 0;
		//printf("cposx:%f\n", r.cpos.x);
		//printf("cposy:%f\n\n", r.cpos.y);
		r.mpos.x = floor(r.cpos.x);
		r.mpos.y = floor(r.cpos.y);
		world2Map[r.mpos.y][r.mpos.x] = worldMap[r.mpos.y][r.mpos.x];

		mlx_pixel_put(cub.mlx, cub.win, (int)((r.cpos.x) * 16), (int)((r.cpos.y) * 16), 16776960);
	}
	return(r);
}

int raycasting(t_cub cub)
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
	draw_minimap(cub);
	while ((int)r_angle <= ((int)cub.dir_a + (int)cub.fov / 2)*100)
	{
		r.cpos = cub.pos;
		if (r_angle != 9000 && r_angle != 18000)
			r = send_ray(r, r_angle, cub);
		draw(cub, r, x);
		x++;
		r_angle = (r_angle + i);
	}
	int ii = 23;
	int ii2;

	world2Map[(int)cub.pos.y][(int)cub.pos.x] = 8;

	while (ii >= 0)
	{
		ii2 = 0;
		while (ii2 < 24)
		{
			printf("%i ", world2Map[ii][ii2]);
			ii2++;
		}
		printf("\n");
		ii--;
	}

	printf("ray from:%f\n", (cub.dir_a - (cub.fov/2)));
	printf("ray to:%f\n", (cub.dir_a + (cub.fov / 2)));

	return (0);
}

int key_hook(int key, t_cub *cub)
{


	if (key == 124)
	{
		cub->dir_a = cub->dir_a + 10;
		if (cub->dir_a >= 360)
			cub->dir_a = cub->dir_a - 360;
		printf("%f\n", cub->dir_a);
	}
	if (key == 123)
	{
		cub->dir_a = cub->dir_a - 10;
		if (cub->dir_a <= 0)
			cub->dir_a = 360 - fabs(cub->dir_a);
		printf("%f\n", cub->dir_a);
	}

	if (key == 125)
	{
		if (cub->fov < 360)
			cub->fov = cub->fov + 10;
		printf("%f\n", cub->fov);
	}
	if (key == 126)
	{
		if (cub->fov > 10)
			cub->fov = cub->fov - 10;
		printf("%f\n", cub->fov);
	}

	mlx_clear_window(cub->mlx, cub->win);
	raycasting(*cub);
	return (0);
}

int main(void)
{
	t_cub cub;

	cub = (t_cub) {
		.fov = 80,
		.pos.x = 12,
		.pos.y = 12,
		.dir_a = 310,
		.conf = &((t_conf) {
			.res.x = 500,
			.res.y = 500
		})
	};
	cub.mlx = mlx_init();
	cub.win = mlx_new_window(cub.mlx, cub.conf->res.x, cub.conf->res.x, "cub3D");
	raycasting(cub);
	cub.dir_a += 10;
	mlx_key_hook(cub.win, &key_hook, &cub);
	mlx_loop(cub.mlx);
}

// TODO 4quarts