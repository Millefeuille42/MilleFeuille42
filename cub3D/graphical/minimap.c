/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 14:06:41 by mlabouri          #+#    #+#             */
/*   Updated: 2020/04/10 18:38:31 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/graphical.h"

inline static void	d_square(int y, int x, t_win cub, t_col col)
{
	int i;
	int i2;

	i = 0;
	while (i < 4)
	{
		i2 = 0;
		while (i2 < 4)
		{
			image_pixel_put(x * 4 + i2, y * 4 + i, cub.img, col);
			i2++;
		}
		i++;
	}
}

void				minimap(t_win cub)
{
	int		i;
	int		i2;
	t_col	col;

	i = 0;
	col = (t_col) {255, 225, 255};
	while (cub.conf->map[i])
	{
		i2 = 0;
		while (cub.conf->map[i][i2])
		{
			if (cub.conf->map[i][i2] != '0')
				d_square(i, i2, cub, (t_col) {0, 255, 0});
			else
				d_square(i, i2, cub, (t_col) {0, 0, 255});
			i2++;
		}
		i++;
	}
	d_square(floor(cub.conf->pos.y), floor(cub.conf->pos.x), cub, col);
}
