/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 10:32:13 by mlabouri          #+#    #+#             */
/*   Updated: 2020/03/10 10:16:48 by mlabouri         ###   ########          */
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
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,1,1,1,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,1,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
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

static void draw(t_cub cub, t_ray r, int x)
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
		//	//mlx_pixel_put(cub.mlx, cub.win, x, draw_s, 255/2);
		//else
			//mlx_pixel_put(cub.mlx, cub.win, x, draw_s, 255);
		draw_s++;
	}
}

static t_ray send_ray(t_ray r, double r_angle)
{
	r.dir.x = cos((r_angle / 100) * M_PI / 180) + r.cpos.x;
	r.dir.y = sin((r_angle / 100) * M_PI / 180) + r.cpos.y;

	r.coef.x = (r.dir.y - r.cpos.y) / (r.dir.x - r.cpos.x);
//	r.coef.y = (r.dir.x - r.cpos.x) / (r.dir.y - r.cpos.y);
	r.mpos.x = floor(r.cpos.x);
	r.mpos.y = floor(r.cpos.y);
	printf("coefx:%f\n", r.coef.x);
	printf("r_angle:%f\n", r_angle);
		printf("dirx:%f\n", r.dir.x);
		printf("diry:%f\n", r.dir.y);
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

		if (r.cpos.x < 0 || r.cpos.x > 23)
			break;
		if (r.cpos.y < 0 || r.cpos.y > 23)
			break;
		printf("cposx:%f\n", r.cpos.x);
		printf("cposy:%f\n\n", r.cpos.y);
		r.mpos.x = floor(r.cpos.x);
		r.mpos.y = floor(r.cpos.y);
		world2Map[r.mpos.y][r.mpos.x] = worldMap[r.mpos.y][r.mpos.x];
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
	while ((int)r_angle <= ((int)cub.dir_a + (int)cub.fov / 2)*100)
	{
		r.cpos = cub.pos;
		if (r_angle != 9000 && r_angle != 18000)
			r = send_ray(r, r_angle);
		draw(cub, r, x);
		x++;
		r_angle = (r_angle + i);
	}
	int ii = 0;
	int ii2;

	world2Map[(int)cub.pos.y][(int)cub.pos.x] = 8;

	while (ii < 24)
	{
		ii2 = 0;
		while (ii2 < 24)
		{
			printf("%i ", world2Map[ii][ii2]);
			ii2++;
		}
		printf("\n");
		ii++;
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

	//mlx_clear_window(cub->mlx, cub->win);
	raycasting(*cub);
	return (0);
}

int main(void)
{
	t_cub cub;

	cub = (t_cub) {
		.fov = 80,
		.pos.x = 5,
		.pos.y = 4,
		.dir_a = 120,
		.conf = &((t_conf) {
			.res.x = 500,
			.res.y = 500
		})
	};
	//cub.mlx = mlx_init();
	//cub.win = mlx_new_window(cub.mlx, cub.conf->res.x, cub.conf->res.x, "cub3D");
	//while (cub.dir_a < 360)
	//{
		raycasting(cub);
	//	cub.dir_a += 10;
	//}
	//mlx_key_hook(cub.win, &key_hook, &cub);
	//mlx_loop(cub.mlx);
}

// TODO 4quarts