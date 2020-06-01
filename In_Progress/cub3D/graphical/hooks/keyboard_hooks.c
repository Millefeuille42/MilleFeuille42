/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 14:06:41 by mlabouri          #+#    #+#             */
/*   Updated: 2020/05/18 11:12:44 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/graphical.h"

inline static int	key_check(int key)
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

int					key_rhook(int key, t_win *cub)
{
	if (key_check(key))
		cub->keys.keyc[key] = 0;
	return (0);
}

int					keyp_hook(int key, t_win *cub)
{
	if (key_check(key))
		cub->keys.keyc[key] = 1;
	return (0);
}

t_win				keys_init(t_win cub)
{
	int i;

	i = 0;
	while (i < 66000)
	{
		cub.keys.keyc[i] = 0;
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
