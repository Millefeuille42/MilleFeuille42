/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:31:05 by mlabouri          #+#    #+#             */
/*   Updated: 2021/12/03 13:32:27 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Mathieu LABOURIER on 25/07/2021.
//

#include "../so_long.h"

inline static void	d_sqr(t_ivec pos, t_app app, t_col col, t_ivec max)
{
	int	i;
	int	i2;

	i = 0;
	while (i < SCREEN_Y / max.y + 1)
	{
		i2 = 0;
		while (i2 < (SCREEN_X / max.x) + 1)
		{
			image_pixel_put((t_ivec){pos.x * SCREEN_X / max.x + i2,
				pos.y * SCREEN_Y / max.y + i}, app.mlx.img, col);
			i2++;
		}
		i++;
	}
}

inline static void	minimap(t_app app)
{
	int			i;
	int			i2;
	int			i3;
	t_element	*cur;

	i = 0;
	cur = app.map.start;
	while (cur)
	{
		i2 = 0;
		while (((char *)cur->data)[i2])
		{
			i3 = 0;
			while (((char *)cur->data)[i2] != MAP_SET[i3] && i3 < 5)
				i3++;
			d_sqr((t_ivec){i2, i}, app, app.colors[i3],
				(t_ivec){(int)ft_strlen(cur->data), app.map.size});
			i2++;
		}
		cur = cur->next;
		i++;
	}
}

int	update(t_app *app)
{
	minimap(*app);
	mlx_put_image_to_window(app->mlx.mlx, app->mlx.win,
		app->mlx.img.v_img, 0, 0);
	return (0);
}
