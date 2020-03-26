/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 16:44:04 by mlabouri          #+#    #+#             */
/*   Updated: 2020/03/26 17:49:08 by millefeuille     ###   ########lyon.fr   */
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
	else if (key == R_UP)
		r_up(cub);
	else if (key == R_DOWN)
		r_down(cub);
	else if (key == R_LEFT)
		r_left(cub);
	else if (key == R_RIGHT)
		r_right(cub);
	else if (key == ESCAPE)
		escape(cub);
}

static int key_check(int key, t_win **cub)
{
	if (key == UP
		|| key == DOWN
		|| key == LEFT
		|| key == RIGHT
		|| key == R_UP
		|| key == R_DOWN
		|| key == R_LEFT
		|| key == R_RIGHT
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
	cub->img = create_image(*cub);
	cub->keys.keyc[key] = 1;
	if (cub->keys.keyc[key] && key_check(key, &cub))
		key_f(key, &cub);
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
	while (i < 66000)
	{
		cub.keys.keyc[i]= 0;
		i++;
	}
	cub.keys.keyl[0] = UP;
	cub.keys.keyl[1] = DOWN;
	cub.keys.keyl[2] = LEFT;
	cub.keys.keyl[3] = RIGHT;
	cub.keys.keyl[4] = R_LEFT;
	cub.keys.keyl[5] = R_RIGHT;
	cub.keys.keyl[6] = ESCAPE;
	return (cub);
}