/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 10:30:08 by mlabouri          #+#    #+#             */
/*   Updated: 2020/03/25 20:45:47 by millefeuille     ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(void)
{
	int fd;
	int err;
	int i = 0;
	t_conf conf;

	err = 0;
	conf = (t_conf) {.fov = 90};
	fd = open("cub3D/sample.cub", O_RDONLY);
	err = cub_parser(fd, &conf);
	printf("\nRes: %i by %i", conf.res.x, conf.res.y);
	printf("\nFloor: %i,%i,%i", conf.floor.r, conf.floor.g, conf.floor.b);
	printf("\nRoof: %i,%i,%i", conf.roof.r, conf.roof.g, conf.roof.b);
	printf("\nNorth: %s\nSouth: %s\nEast: %s\nWest: %s\nSprite: %s", conf.no.path, conf.so.path, conf.ea.path,
		   conf.we.path, conf.sprite.path);
	printf("\nPos: %i, %i", (int)conf.pos.x, (int)conf.pos.y);
	printf("\nDir: %i", (int)conf.dir_a);
	printf("\nerr: %i", err);
	printf("\nmap:\n");
		while (conf.map[i])
		{
			printf("%s\n", conf.map[i]);
			i++;
		}
	deinit_conf(&conf);
}
/*
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
*/
// TODO
//		- Safe exiting
//		- Proper Map Check
//		- Movement
//		- Proper KeyMapping
//		- Error Handling
//		- Orchestration