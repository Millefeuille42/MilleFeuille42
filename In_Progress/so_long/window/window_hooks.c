/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:31:19 by mlabouri          #+#    #+#             */
/*   Updated: 2021/12/03 13:31:35 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Millefeuille on 28/06/2021.
//

#include "../so_long.h"

int	quit(t_app *app)
{
	mlx_destroy_window(app->mlx.mlx, app->mlx.win);
	if (app->mlx.img.v_img)
		mlx_destroy_image(app->mlx.mlx, app->mlx.img.v_img);
	mlx_destroy_display(app->mlx.mlx);
	free(app->mlx.mlx);
	list_iter(&app->map, free_map);
	list_iter_free(&app->map);
	exit(0);
}

int	key_press_hook(int key, t_app *app)
{
	static int		keys[4] = {LEFT, DOWN, RIGHT, UP};
	static void		(*actions[4])(t_app *) = {m_left, m_down, m_right, m_up};
	int				i;

	i = 0;
	if (key == ESCAPE)
		quit(app);
	while (i < 4)
	{
		if (key == keys[i])
			actions[i](app);
		i++;
	}
	update(app);
	return (0);
}
