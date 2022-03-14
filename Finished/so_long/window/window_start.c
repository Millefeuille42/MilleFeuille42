/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:32:11 by mlabouri          #+#    #+#             */
/*   Updated: 2021/12/03 13:32:11 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Millefeuille on 28/06/2021.
//

#include "../so_long.h"

int	app_event_hooks(t_app *app)
{
	app->mlx.img = create_image(*app);
	mlx_hook(app->mlx.win, KeyPress, KeyPressMask, &key_press_hook, app);
	mlx_hook(app->mlx.win, DestroyNotify, StructureNotifyMask, &quit, app);
	mlx_hook(app->mlx.win, VisibilityNotify, VisibilityChangeMask,
		&update, app);
	mlx_loop(app->mlx.mlx);
	return (0);
}

int	app_start_window(t_app *app)
{
	app->mlx.mlx = mlx_init();
	app->mlx.win = mlx_new_window(app->mlx.mlx, SCREEN_X, SCREEN_Y, WIN_NAME);
	app->mlx.img.v_img = NULL;
	app->mlx.img = create_image(*app);
	update(app);
	app_event_hooks(app);
	return (0);
}
