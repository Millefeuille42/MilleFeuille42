/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 10:32:13 by mlabouri          #+#    #+#             */
/*   Updated: 2020/03/11 19:13:10 by mlabouri         ###   ########.fr       */
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

static t_cub draw(t_cub cub, t_ray r, int x)
{
	int draw_s;
	int draw_e;
	double dist;
	int i;

	dist = sqrt(pow(cub.pos.x - r.cpos.x, 2) + pow(cub.pos.y - r.cpos.y, 2));
	int lineHeight = (int)(cub.conf->res.y / dist);
	if (dist == 0)
		lineHeight = 0;
	draw_s = -lineHeight / 2 + cub.conf->res.y / 2;
	if (draw_s < 0)
		draw_s = 0;
	draw_e = lineHeight / 2 + cub.conf->res.y / 2;
	if (draw_e >= cub.conf->res.y)
		draw_e = cub.conf->res.y - 1;

	if (x >= cub.conf->res.x)
		return cub;
	i = 0;
	while (i < draw_s )
	{
		//printf("|%i\n", i);
		cub.c_ima[i * cub.sl + x * (cub.bpp/8)] = (char)0;
		cub.c_ima[i * cub.sl + x * (cub.bpp/8) + 1] = (char)125;
		cub.c_ima[i * cub.sl + x * (cub.bpp/8) + 2] = (char)(125);
		i++;
	}
	i = draw_e;
	while (i  < (cub.conf->res.y - 1))
	{
		//printf("%i\n", i);
		cub.c_ima[i * cub.sl + x * (cub.bpp/8)] = (char)125;
		cub.c_ima[i * cub.sl + x * (cub.bpp/8) + 1] = (char)0;
		cub.c_ima[i * cub.sl + x * (cub.bpp/8) + 2] = (char)0;
		i++;
	}
	while (draw_s < draw_e )
	{
		cub.c_ima[draw_s * cub.sl + x * (cub.bpp/8)] = (char)((255*1.5)/(dist));
		cub.c_ima[draw_s * cub.sl + x * (cub.bpp/8) + 1] = (char)(255*1.5/(dist));
		cub.c_ima[draw_s * cub.sl + x * (cub.bpp/8) + 2] = (char)(255*1.5/(dist));
		draw_s++;
	}

	return (cub);
}

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
static char keyc[255]= {};

int key_hook(int key, t_cub *cub)
{

	keyc[key] = 1;
	if (cub->v_img)
		mlx_destroy_image(cub->mlx, cub->v_img);
	cub->v_img = mlx_new_image(cub->mlx, cub->conf->res.x, cub->conf->res.y);
	cub->c_ima = mlx_get_data_addr(cub->v_img, &cub->bpp, &cub->sl, &cub->endian);
	if (key == 124 || keyc[124] == 1)
	{
		cub->dir_a = cub->dir_a + 10;
		if (cub->dir_a >= 360)
			cub->dir_a = cub->dir_a - 360;
		printf("%f\n", cub->dir_a);
	}
	else if (key == 123 || keyc[123] == 1)
	{
		cub->dir_a = cub->dir_a - 10;
		if (cub->dir_a <= 0)
			cub->dir_a = 360 - fabs(cub->dir_a);
		printf("%f\n", cub->dir_a);
	}
	else if (key == 125 || keyc[125] == 1)
	{
		if (cub->fov < 140)
			cub->fov = cub->fov + 10;
		printf("%f\n", cub->fov);
	}
	else if (key == 126 || keyc[126] == 1)
	{
		if (cub->fov > 10)
			cub->fov = cub->fov - 10;
		printf("%f\n", cub->fov);
	}
	else if (key != 0)
		return (0);
	raycasting(*cub);
	mlx_clear_window(cub->mlx, cub->win);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->v_img, 0, 0);
	return (0);
}

int key_rhook(int key, t_cub *cub)
{
	keyc[key] = 0;
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
			.res.x = 1920,
			.res.y = 1080
		})
	};
	cub.mlx = mlx_init();
	cub.win = mlx_new_window(cub.mlx, cub.conf->res.x, cub.conf->res.y, "cub3D");
	key_hook(0, &cub);
	if (keyc[124] == 1 || keyc[125] == 1 || keyc[123] == 1 || keyc[126] == 1)
		key_hook(0, &cub);
	mlx_hook(cub.win, 2, (1L<<0), &key_hook, &cub);
	mlx_hook(cub.win, 3, (1L<<0), &key_rhook, &cub);

	mlx_loop(cub.mlx);

}
