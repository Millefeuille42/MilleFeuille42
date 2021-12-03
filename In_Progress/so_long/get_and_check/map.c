/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:35:05 by mlabouri          #+#    #+#             */
/*   Updated: 2021/12/03 13:35:05 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Millefeuille on 22/06/2021.
//

#include "../so_long.h"

inline static int	gnl_wrapper(int fd, char **line, int *ret)
{
	*ret = get_next_line(fd, line);
	return (*ret);
}

inline static void	assign_line(t_app *app, char *line)
{
	if (*line)
	{
		if (!app->map.start)
			app->map = new_list(line);
		else
			list_append(&app->map, line);
	}
	else
		free(line);
}

inline static int	get_map(t_app *app)
{
	char	*line;
	int		ret;

	while (gnl_wrapper(app->config_fd, &line, &ret))
	{
		if (ret < 0)
		{
			if (line)
				free(line);
			return (ret_error("get_next_line\n", -1));
		}
		assign_line(app, line);
	}
	assign_line(app, line);
	return (0);
}

int	get_and_check_map(t_app *app)
{
	app->map.start = NULL;
	if (get_map(app))
		return (-1);
	if (check_map_char(app))
		return (-1);
	if (check_map_walls(app))
		return (-1);
	return (0);
}
