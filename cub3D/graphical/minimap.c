/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: {author_and_email}                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 16:00:11 by millefeuille      #+#    #+#             */
/*   Updated: 2020/03/27 09:48:36 by millefeuille     ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "graphical.h"


static void d_square(int y, int x, t_win cub, t_plan col)
{
	int i;
	int i2;

	i = 0;
	while (i < 4)
	{
		i2 = 0;
		while (i2 < 4)
		{
			image_pixel_put(x * 4 + i2, y * 4 + i,cub.img, col);
			i2++;
		}
		i++;
	}
}

void minimap(t_win cub)
{
	int i;
	int i2;
	t_plan col;

	i = 0;
	col = (t_plan) {255, 2525, 255};
	while (cub.conf->map[i])
	{
		i2 = 0;
		while (cub.conf->map[i][i2])
		{
			if (cub.conf->map[i][i2] != '0')
				d_square(i, i2, cub, (t_plan) {0, 255, 0});
			else
				d_square(i, i2, cub, (t_plan) {0, 0, 255});
			i2++;
		}
		i++;
	}
	d_square(floor(cub.conf->pos.y), floor(cub.conf->pos.x), cub, col);
}