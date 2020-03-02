/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:33:35 by mlabouri          #+#    #+#             */
/*   Updated: 2020/03/02 19:13:59 by mlabouri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <mlx.h>
#include <string.h>
#include <errno.h>

int main(void)
{
	int fd;
	int err;
	t_cub conf;
	void *mlxptr;
	void *winptr;

	conf = (t_cub) {};
	errno = 0;


	fd = open("./sample.cub", O_RDONLY);

	if ((err = cub_parser(fd, &conf)) >= 0 && !errno)
	{
		printf("\nRes: %i by %i", conf.res.x, conf.res.y);
		printf("\nFloor: %i,%i,%i", conf.floor.r, conf.floor.g, conf.floor.b);
		printf("\nRoof: %i,%i,%i", conf.roof.r, conf.roof.g, conf.roof.b);
		printf("\nNorth: %s\nSouth: %s\nEast: %s\nWest: %s\nSprite: %s", conf.no.path, conf.so.path, conf.ea.path,
			   conf.we.path, conf.sprite.path);
		printf("\nmap:\n");
		while (conf.map[err])
		{
			printf("%s\n", conf.map[err]);
			err++;
		}
	}
	printf("%i\n", err);
	deinit_conf(&conf);
	mlxptr = mlx_init();
	winptr = mlx_new_window(mlxptr, 500, 500, "test");
	int i = 16711680;
	int x = 0;
	int y = 0;
	while (1)
	{
		mlx_pixel_put(mlxptr, winptr, x, y, i);
		x++;
		if (x == 500)
		{
			x = 0;
			y++;
		}
		if (y == 500)
			break;
		printf("%i\n", i);
	}
	mlx_loop(mlxptr);
}

// TODO
//		- Safe exiting
//		- Proper Map Check