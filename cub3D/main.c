/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 10:30:08 by mlabouri          #+#    #+#             */
/*   Updated: 2020/03/19 09:23:21 by millefeuille     ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*

int main(void)
{
	int fd;
	int err;
	t_conf conf;

	conf = (t_conf) {};
	fd = open("./sample.cub", O_RDONLY);
	if ((err = cub_parser(fd, &conf)) >= 0)
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
	deinit_conf(&conf);
}
 */

int main (void)
{
	t_conf conf;

	conf = (t_conf) {
			.fov = 80,
			.pos.x = 12,
			.pos.y = 12,
			.dir_a = 310,
			.res.x = 1920,
			.res.y = 1080
	};
	graphics(&conf);
}

// TODO
//		- Safe exiting
//		- Proper Map Check
//		- Movement
//		- Proper KeyMapping
//		- Error Handling
//		- Orchestration