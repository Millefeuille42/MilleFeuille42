/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:34:44 by mlabouri          #+#    #+#             */
/*   Updated: 2021/12/03 13:34:44 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	free_map(t_element *el)
{
	free(el->data);
	return (0);
}

int	get_and_check(t_app *app, int argc, char **argv)
{
	app->config_fd = get_and_check_arguments(argc, argv);
	if (app->config_fd < 0)
		return (1);
	if (get_and_check_map(app))
	{
		list_iter(&app->map, free_map);
		list_iter_free(&app->map);
		return (2);
	}
	app->mov_num = 0;
	app->colors[WALL] = (t_col){255, 255, 255};
	app->colors[COLL] = (t_col){0, 255, 0};
	app->colors[EXIT] = (t_col){255, 0, 0};
	app->colors[PLAY] = (t_col){0, 0, 255};
	app->colors[VOID] = (t_col){0, 0, 0};
	return (0);
}

int	main(int argc, char **argv)
{
	t_app	app;

	if (get_and_check(&app, argc, argv))
		return (1);
	app_start_window(&app);
	list_iter(&app.map, free_map);
	list_iter_free(&app.map);
}
