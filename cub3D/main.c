/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:33:35 by mlabouri          #+#    #+#             */
/*   Updated: 2020/03/03 16:37:56 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(void)
{
	int fd;
	int err;
	t_cub conf;


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
	conf.mlxptr = mlx_init();
	conf.winptr = mlx_new_window(conf.mlxptr, conf.res.x, conf.res.y, "cub3D");
	mlx3D(conf);
	mlx_loop(conf.mlxptr);
	deinit_conf(&conf);
}

// TODO
//		- Safe exiting
//		- Proper Map Check