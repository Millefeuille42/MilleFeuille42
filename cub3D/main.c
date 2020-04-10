/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 14:06:41 by mlabouri          #+#    #+#             */
/*   Updated: 2020/04/10 15:07:18 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(void)
{
	int fd;
	int err;
	int i = 0;
	t_conf conf;

	conf = (t_conf) {.fov = 60};
	fd = open("cub3D/sample.cub", O_RDONLY);
	err = cub_parser(fd, &conf);
	printf("\nRes: %i by %i", conf.res.x, conf.res.y);
	printf("\nFloor: %i,%i,%i", conf.floor.r, conf.floor.g, conf.floor.b);
	printf("\nRoof: %i,%i,%i", conf.roof.r, conf.roof.g, conf.roof.b);
	printf("\nNorth: %s\nSouth: %s\nEast: %s\nWest: %s\nSprite: %s", conf.no.path, conf.so.path, conf.ea.path,
		   conf.we.path, conf.sprite.path);
	printf("\nPos: %i, %i", (int)conf.pos.x, (int)conf.pos.y);
	printf("\nDir: %i", (int)conf.dir_a);
	printf("\nmap:\n");
	while (conf.map[i])
	{
		printf("%s\n", conf.map[i]);
		i++;
	}
	graphics(&conf);
	return (abs(err));
}


// TODO
//		- Safe exiting
//		- Proper Map Check
//		- Movement
//		- Proper KeyMapping
//		- Error Handling
//		- Orchestration