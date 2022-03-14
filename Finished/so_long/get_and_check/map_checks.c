/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:35:09 by mlabouri          #+#    #+#             */
/*   Updated: 2021/12/03 13:35:09 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Millefeuille on 25/06/2021.
//

#include "../so_long.h"

inline static int	check_map_vert_walls(t_app *app)
{
	char	*line;
	char	*line2;
	int		i;

	line = (char *)app->map.start->data;
	line2 = (char *)app->map.end->data;
	i = 0;
	while (line[i] && line2[i])
	{
		if (line[i] != '1' || line2[i] != '1')
			return (-1);
		i++;
	}
	if (line[i] || line2[i])
		return (-2);
	return (0);
}

inline static int	check_map_side_walls(t_app *app)
{
	t_element	*cur;
	char		*line;
	int			size;
	int			cur_size;

	cur = app->map.start;
	size = (int)ft_strlen((char *)cur->data);
	while (cur->next)
	{
		line = (char *)cur->data;
		cur_size = (int)ft_strlen(line);
		if (cur_size != size)
			return (-2);
		if (line[0] != '1' || line[cur_size - 1] != '1')
			return (-1);
		cur = cur->next;
	}
	return (0);
}

int	check_map_walls(t_app *app)
{
	int	err;

	err = check_map_vert_walls(app);
	if (err == -1)
		return (ret_error("map: Invalid boundaries\n", -1));
	if (err == -2)
		return (ret_error("map: Invalid shape\n", -2));
	err = check_map_side_walls(app);
	if (err == -1)
		return (ret_error("map: Invalid boundaries\n", -1));
	if (err == -2)
		return (ret_error("map: Invalid shape\n", -2));
	return (0);
}

inline static int	check_map_elements(t_app *app)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (app->set[i++] <= 0)
			return (ret_error("map: Missing element\n", -1));
	}
	if (app->set[2] > 1)
		return (ret_error("map: Too many players\n", -1));
	return (0);
}

int	check_map_char(t_app *app)
{
	t_element	*cur;
	int			i;

	cur = app->map.start;
	i = 0;
	while (i < 4)
		app->set[i++] = 0;
	while (cur->next)
	{
		i = 0;
		while (((char *)cur->data)[i])
		{
			if (!ft_cinset(((char *)cur->data)[i++], MAP_SET))
				return (ret_error("map: Invalid character", -1));
			app->set[get_charset_index(((char *)cur->data)[i], MAP_SUB_SET)]++;
		}
		cur = cur->next;
	}
	return (check_map_elements(app));
}
