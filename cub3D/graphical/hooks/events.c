/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 16:20:07 by mlabouri          #+#    #+#             */
/*   Updated: 2020/03/12 19:36:30 by mlabouri         ###   ########          */
/*                                                                            */
/* ************************************************************************** */

#include "../graphical.h"

static int 	quit(t_win **cub)
{
	deinit_conf((*cub)->conf);
	exit(0);
}

static int event_hooks(t_win *cub)
{
	mlx_hook(cub->win, 2, (1L<<0),
			&keyp_hook, cub);
	mlx_hook(cub->win, 3, (1L<<1),
			&key_rhook, cub);
	mlx_hook(cub->win, 17, 0,
			&quit, cub);
	mlx_loop(cub->mlx);
}

int graphics(t_conf *conf)
{
	t_win cub;

	cub = (t_win) {
			.conf = &((t_conf) {
					.fov = 80,
					.pos.x = 12,
					.pos.y = 12,
					.dir_a = 310,
					.res.x = 1920,
					.res.y = 1080
			})
	};
	cub = keys_init(cub);
	cub.mlx = mlx_init();
	cub.win = mlx_new_window(cub.mlx, cub.conf->res.x,
							 cub.conf->res.y, "cub3D");
	event_hooks(&cub);
	return (0);
}
