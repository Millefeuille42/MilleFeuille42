/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_methods_3.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 13:09:17 by mlabouri          #+#    #+#             */
/*   Updated: 2020/05/18 13:09:17 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

inline static char	*replace(char *str, int len)
{
	char	*tmp;
	int		i;

	tmp = str;
	if (!(str = malloc(sizeof(char) * len + 1)))
		return (NULL);
	i = 0;
	while (tmp[i])
	{
		str[i] = tmp[i];
		i++;
	}
	while (i < len)
	{
		str[i] = '1';
		i++;
	}
	free(tmp);
	str[len] = '\0';
	return (str);
}

inline static int	borders_h(char **map, t_map_prop prop)
{
	int x;
	int min_c;
	int max_c;

	x = 0;
	min_c = 0;
	max_c = prop.lines - 1;
	while (map[min_c][x])
	{
		if (map[min_c][x] != '1' && (x = -1))
			min_c++;
		if (max_c - min_c < 3)
			return (-22);
		x++;
	}
	x = 0;
	while (map[min_c][x])
	{
		if (map[max_c][x] != '1' && (x = -1))
			max_c--;
		if (max_c - min_c < 3)
			return (-22);
		x++;
	}
	return (0);
}

inline static int	borders_w(char **map)
{
	int y;
	int min_c;
	int max_c;

	y = 0;
	min_c = 0;
	max_c = (int)ft_strlen(map[0]) - 1;
	while (map[y])
	{
		if (map[y][min_c] != '1' && (y = -1))
			min_c++;
		if (max_c - min_c < 3)
			return (-22);
		y++;
	}
	y = 0;
	while (map[y])
	{
		if (map[y][max_c] != '1' && (y = -1))
			max_c--;
		if (max_c - min_c < 3)
			return (-22);
		y++;
	}
	return (0);
}

int					check_lim(char **map, t_map_prop prop)
{
	int y;
	int m_len;
	int r_len;

	y = 0;
	m_len = 0;
	while (map[y])
		if ((r_len = ft_strlen(map[y++])) > m_len)
			m_len = r_len;
	y = 0;
	while (map[y])
	{
		if ((int)ft_strlen(map[y]) < m_len)
			if (!(map[y] = replace(map[y], m_len)))
				return (-3);
		y++;
	}
	if (borders_h(map, prop))
		return (-22);
	return (borders_w(map));
}
