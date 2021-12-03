/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:32:15 by mlabouri          #+#    #+#             */
/*   Updated: 2021/12/03 13:32:21 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Millefeuille on 28/06/2021.
//

#include "../so_long.h"

t_img	image_pixel_put(t_ivec d, t_img i, t_col c)
{
	if (d.x >= SCREEN_X || d.x < 0 || d.y >= SCREEN_Y || d.y < 0)
		return (i);
	i.c_img[d.y * i.sl + d.x * (i.bpp / 8)] = (char)c.b;
	i.c_img[d.y * i.sl + d.x * (i.bpp / 8) + 1] = (char)c.g;
	i.c_img[d.y * i.sl + d.x * (i.bpp / 8) + 2] = (char)c.r;
	return (i);
}

t_img	create_image(t_app app)
{
	t_img	img;

	img = app.mlx.img;
	if (img.v_img)
		mlx_destroy_image(app.mlx.mlx, img.v_img);
	img.v_img = mlx_new_image(app.mlx.mlx, SCREEN_X, SCREEN_Y);
	img.c_img = mlx_get_data_addr(img.v_img, &img.bpp, &img.sl, &img.endian);
	return (img);
}
