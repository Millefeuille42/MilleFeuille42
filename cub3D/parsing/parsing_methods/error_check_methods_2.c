/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_methods_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 10:30:08 by mlabouri          #+#    #+#             */
/*   Updated: 2020/03/10 14:32:12 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

static int linecount(char **map, t_dbl_co *pos)
{
	int i;
	int i2;

	i = 0;
	while (map[i])
	{
		i2 = 0;
		while (map[i][i2])
		{
			if (!(ft_cinset(map[i][i2], "102NSWO ")))
				return (-2);
			if (ft_cinset(map[i][i2], "NSWO"))
			{
				if (*pos)
					return (-2);
				else
					*pos = map[i][i2];
			}
			i2++;
		}
		i++;
	}
	if (i < 3)
		return (-2);
	return (i);
}

int map_e(char **map, t_dbl_co *pos)
{
	int len;
	int lines;
	int i[2];

	i[0] = 0;
	if ((lines = linecount(map, pos)) < 3)
		return (-2);

	return (0);
}