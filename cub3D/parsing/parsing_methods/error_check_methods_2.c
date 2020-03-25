/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_methods_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 10:30:08 by mlabouri          #+#    #+#             */
/*   Updated: 2020/03/25 20:44:34 by millefeuille     ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

static t_conf def_pos(t_conf conf, int y, int x, char dir)
{
	conf.pos.x = (double)x;
	conf.pos.y = (double)y;
	if (dir == 'N')
		conf.dir_a = 90;
	else if (dir == 'W')
		conf.dir_a = 180;
	else
		conf.dir_a = 270;
	return (conf);
}

static int	read_pos(t_map_properties mp, t_conf *conf, char **map)
{
	if (ft_cinset(map[mp.y][mp.x], "NSWO"))
	{
		if (conf->dir_a)
			return (-22);
		else
			*conf = def_pos(*conf, mp.y, mp.x, map[mp.y][mp.x]);
	}
	else if (ft_cinset(map[mp.y][mp.x], "102 "))
	{
		if (map[mp.y][mp.x] == ' ')
			map[mp.y][mp.x] = '1';
		if ((mp.y == 0 || mp.y > mp.lines) && map[mp.y][mp.x] != '1')
			return (-22);
	}
	return (0);
}

int map_e(char **map, t_conf *conf)
{
	t_map_properties prop;

	prop.y = 0;
	prop.lines = 0;
	while (map[prop.lines])
		prop.lines++;
	while (map[prop.y])
	{
		prop.x = 0;
		prop.length = 0;
		while (map[prop.y][prop.length])
			prop.length++;
		while (map[prop.y][prop.x])
		{
			if (read_pos(prop, conf, map))
				return (-2);
			prop.x++;
		}
		prop.y++;
	}
	return (0);
}