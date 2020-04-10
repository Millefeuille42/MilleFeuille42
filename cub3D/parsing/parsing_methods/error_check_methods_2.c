/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_methods_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 14:06:41 by mlabouri          #+#    #+#             */
/*   Updated: 2020/04/10 15:26:00 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

static int	check_lim(t_map_prop mp, char **map)
{
	(void)mp;
}

static int	read_pos(t_map_prop mp, t_conf *conf, char *m)
{
	if (ft_cinset(*m, "NSWO"))
	{
		if (conf->dir_a)
			return (-22);
		conf->pos.x = (double)mp.x;
		conf->pos.y = (double)mp.y;
		if (*m == 'N')
			conf->dir_a = 90;
		else if (*m == 'W')
			conf->dir_a = 180;
		else
			conf->dir_a = 270;
		*m = '0';
	}
	else if (ft_cinset(*m, "1025 "))
	{
		if (*m == ' ')
			*m = '5';
		if ((mp.y == 0 || mp.y == mp.lines - 1) && !ft_cinset(*m, "15"))
			return (-22);
	}
	return (0);
}

int			map_e(char **map, t_conf *conf)
{
	t_map_prop prop;

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
			if (read_pos(prop, conf, &map[prop.y][prop.x]))
				return (-2);
			prop.x++;
		}
		prop.y++;
	}
	return (0);
}
