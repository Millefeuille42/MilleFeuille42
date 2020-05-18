/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 14:06:41 by mlabouri          #+#    #+#             */
/*   Updated: 2020/05/18 11:12:44 by mlabouri         ###   ########.fr       */
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

t_col	shade_plane(t_col col, double dist, int in)
{
	col.r = (int)(((double)col.r / 255.0 + 0.1) * ((in * dist / 255.0)));
	col.g = (int)(((double)col.g / 255.0 + 0.1) * ((in * dist / 255.0)));
	col.b = (int)(((double)col.b / 255.0 + 0.1) * ((in * dist / 255.0)));
	col.r = col.r > 255 ? 255 : col.r;
	col.g = col.g > 255 ? 255 : col.g;
	col.b = col.b > 255 ? 255 : col.b;
	col.r = col.r < 0 ? 0 : col.r;
	col.g = col.g < 0 ? 0 : col.g;
	col.b = col.b < 0 ? 0 : col.b;
	return (col);
}


t_col	shade_text(t_col col, double dist)
{
	t_col o_col;

	o_col = col;
	col.r = (int)(((double)col.r / col.r + 0.1) * ((col.r / (0.3 * dist))));
	col.g = (int)(((double)col.g / col.g + 0.1) * ((col.g / (0.3 * dist))));
	col.b = (int)(((double)col.b / col.b + 0.1) * ((col.b / (0.3 * dist))));
	col.r = col.r > o_col.r ? o_col.r : col.r;
	col.g = col.g > o_col.g ? o_col.g : col.g;
	col.b = col.b > o_col.b ? o_col.b : col.b;
	col.r = col.r < o_col.r - 30 ? o_col.r - 30 : col.r;
	col.g = col.g < o_col.g - 30 ? o_col.g - 30 : col.g;
	col.b = col.b < o_col.b - 30 ? o_col.b - 30 : col.b;
	return (col);
}
