/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_methods_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 14:06:41 by mlabouri          #+#    #+#             */
/*   Updated: 2020/04/30 18:34:44 by millefeui        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

inline static int	check_lim(t_map_prop mp, char **map)
{
	if (!(mp.y == 0 || mp.y == mp.lines - 1))
	{
		if (!ft_cinset(map[mp.y][mp.length - 1], "15"))
			return (-22);
		if ((ft_cinset(map[mp.y - 1][mp.length - 2], "15")
		|| ft_cinset(map[mp.y - 1][mp.length - 1], "15")
		|| ft_cinset(map[mp.y - 1][mp.length], "15"))
		&& (ft_cinset(map[mp.y + 1][mp.length - 2], "15")
		|| ft_cinset(map[mp.y + 1][mp.length - 1], "15")
		|| ft_cinset(map[mp.y + 1][mp.length], "15")))
			return (0);
		else
			return (-22);
	}
	return (0);
}

inline static int	read_pos(t_map_prop mp, t_conf *conf, char *m)
{
	if (ft_cinset(*m, "NSWE"))
	{
		if (conf->play.pos.x > 0)
			return (-22);
		conf->play.pos.x = (double)mp.x;
		conf->play.pos.y = (double)mp.y;
		if (*m == 'N')
			rotate_2(&conf->play.dir, &conf->play.plan, 90);
		else if (*m == 'W')
			rotate_2(&conf->play.dir, &conf->play.plan, 180);
		else if (*m == 'E')
			rotate_2(&conf->play.dir, &conf->play.plan, 270);
		*m = '0';
	}
	else if (ft_cinset(*m, "1025 "))
	{
		if (*m == ' ')
			*m = '5';
		if ((mp.y == 0 || mp.y == mp.lines - 1) && !ft_cinset(*m, "15"))
			return (-22);
	}
	else
		return (-22);
	return (0);
}

int					map_e(char **map, t_conf *conf)
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
				return (-22);
			prop.x++;
		}
		if (check_lim(prop, map))
			return (-22);
		prop.y++;
	}
	if (conf->play.pos.x < 0)
		return (-22);
	return (0);
}
