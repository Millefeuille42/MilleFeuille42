/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 14:06:41 by mlabouri          #+#    #+#             */
/*   Updated: 2020/05/18 11:12:44 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/graphical.h"

inline static void	d_sqr(int y, int x, t_win cub, t_col col)
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
			if (cub.conf->map[i][i2] == '1')
				d_sqr(i, i2, cub, (t_col) {0, 255, 0});
			else if (cub.conf->map[i][i2] == '2')
				d_sqr(i, i2, cub, (t_col) {255, 0, 0});
			else
				d_sqr(i, i2, cub, (t_col) {0, 0, 255});
			i2++;
		}
		i++;
	}
	d_sqr(floor(cub.conf->play.pos.y), floor(cub.conf->play.pos.x), cub, col);
}
