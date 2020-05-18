/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 14:06:41 by mlabouri          #+#    #+#             */
/*   Updated: 2020/05/18 11:12:44 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/graphical.h"

t_img				create_image(t_win cub)
{
	t_img img;

	img = cub.img;
	if (img.v_img)
		mlx_destroy_image(cub.mlx, img.v_img);
	img.v_img = mlx_new_image(cub.mlx,
			cub.conf->res.x, cub.conf->res.y);
	img.c_img = mlx_get_data_addr(img.v_img,
			&img.bpp, &img.sl, &img.e);
	return (img);
}

int					quit(void)
{
	exit(0);
}

inline static int	event_hooks(t_win *cub)
{
	char i;

	i = 0;
	cub->img = create_image(*cub);
	while (i++ < 10)
		raycasting(cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img.v_img, 0, 0);
	mlx_hook(cub->win, KeyRelease, KeyReleaseMask,
		&key_rhook, cub);
	mlx_hook(cub->win, KeyPress, KeyPressMask,
			&keyp_hook, cub);
	mlx_hook(cub->win, DestroyNotify, StructureNotifyMask,
			&quit, cub);
	mlx_loop(cub->mlx);
	return (0);
}

int					graphics(t_conf *conf)
{
	t_win		cub;
	t_ivec		ssize;

	cub = (t_win) {.conf = conf};
	cub = keys_init(cub);
	cub.mlx = mlx_init();
	mlx_get_screen_size(cub.mlx, &ssize.x, &ssize.y);
	cub.conf->res.x = cub.conf->res.x > ssize.x ? ssize.x : cub.conf->res.x;
	cub.conf->res.y = cub.conf->res.y > ssize.y ? ssize.y : cub.conf->res.y;
	init_textures(&cub);
	cub.win = mlx_new_window(cub.mlx, cub.conf->res.x,
		cub.conf->res.y, "cub3D");
	event_hooks(&cub);
	return (0);
}
