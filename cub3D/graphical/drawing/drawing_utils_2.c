/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 14:06:41 by mlabouri          #+#    #+#             */
/*   Updated: 2020/04/30 18:34:44 by millefeui        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/graphical.h"

t_img	image_pixel_put(int x, int y, t_img img, t_col color)
{
	img.c_img[y * img.sl + x * (img.bpp / 8)] = (char)color.b;
	img.c_img[y * img.sl + x * (img.bpp / 8) + 1] = (char)color.g;
	img.c_img[y * img.sl + x * (img.bpp / 8) + 2] = (char)color.r;
	return (img);
}

t_col	shade(t_col col, double dist, char way, int in)
{
	if (way)
	{
		col.r = (int)(((double)col.r / 255.0 + 0.1) * (in * (255.0 / dist)));
		col.g = (int)(((double)col.g / 255.0 + 0.1) * (in * (255.0 / dist)));
		col.b = (int)(((double)col.b / 255.0 + 0.1) * (in * (255.0 / dist)));
	}
	else
	{
		col.r = (int)(((double)col.r / 255.0 + 0.1) * (in * (dist / 255.0)));
		col.g = (int)(((double)col.g / 255.0 + 0.1) * (in * (dist / 255.0)));
		col.b = (int)(((double)col.b / 255.0 + 0.1) * (in * (dist / 255.0)));
	}
	col.r = col.r > 255 ? 255 : col.r;
	col.g = col.g > 255 ? 255 : col.g;
	col.b = col.b > 255 ? 255 : col.b;
	col.r = col.r < 0 ? 0 : col.r;
	col.g = col.g < 0 ? 0 : col.g;
	col.b = col.b < 0 ? 0 : col.b;
	return (col);
}
