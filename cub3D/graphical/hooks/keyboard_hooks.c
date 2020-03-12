/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 16:44:04 by mlabouri          #+#    #+#             */
/*   Updated: 2020/03/12 18:04:33 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../graphical.h"

static void	key_f(int key, t_win **cub)
{
	if (key == UP)
		up(cub);
	else if (key == DOWN)
		down(cub);
	else if (key == LEFT)
		left(cub);
	else if (key == RIGHT)
		right(cub);
	else if (key == ESCAPE)
		escape(cub);
}

static int key_check(int key, t_win **cub)
{
	if (key == UP
		|| key == DOWN
		|| key == LEFT
		|| key == RIGHT
		|| key == ESCAPE)
		return (1);
	return (0);
}

int key_rhook(int key, t_win *cub)
{
	if (key_check(key, &cub))
		cub->keys.keyc[key] = 0;
	return (0);
}

int keyp_hook(int key, t_win *cub)
{
	if (cub->img.v_img)
		mlx_destroy_image(cub->mlx, cub->img.v_img);
	cub->img.v_img = mlx_new_image(cub->mlx, cub->conf->res.x,
			cub->conf->res.y);
	cub->img.c_img = mlx_get_data_addr(cub->img.v_img, &cub->img.bpp,
			&cub->img.sl, &cub->img.endian);
	if (cub->keys.keyc[key])
		key_f(key, &cub);
	else if (key_check(key, &cub))
		cub->keys.keyc[key] = 1;
	else
		return (0);

	raycasting(*cub);
	mlx_clear_window(cub->mlx, cub->win);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img.v_img, 0, 0);
	return (0);
}

t_win keys_init(t_win cub)
{
	int i;

	i = 0;
	cub.keys.length = 4;
	while (i < 255)
	{
		cub.keys.keyc[i]= 0;
		i++;
	}
	cub.keys.keyl[0] = UP;
	cub.keys.keyl[1] = DOWN;
	cub.keys.keyl[2] = LEFT;
	cub.keys.keyl[3] = RIGHT;
	cub.keys.keyl[4] = ESCAPE;
	return (cub);
}