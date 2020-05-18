/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_methods_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 14:06:41 by mlabouri          #+#    #+#             */
/*   Updated: 2020/05/18 11:12:44 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

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
		else if (*m == 'S')
			rotate_2(&conf->play.dir, &conf->play.plan, 270);
		*m = '0';
	}
	else if (ft_cinset(*m, "102 "))
	{
		if (*m == ' ')
			*m = '1';
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
		prop.y++;
	}
	if (conf->play.pos.x < 0)
		return (-22);
	if (check_lim(map, prop))
		return (-22);
	return (0);
}
