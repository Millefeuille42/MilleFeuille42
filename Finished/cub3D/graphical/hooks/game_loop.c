/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 12:42:33 by mlabouri          #+#    #+#             */
/*   Updated: 2020/06/03 12:42:33 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/graphical.h"

int		framer(clock_t t, t_win *cub)
{
	double	time_taken;
	double	spf;
	char	*fps;

	t = clock() - t;
	time_taken = ((double)t) / CLOCKS_PER_SEC;
	spf = 1.0 / FPS;
	if (time_taken < spf)
	{
		time_taken = spf;
		nanosleep(&(struct timespec){0, time_taken * 1000000000}, 0);
	}
	fps = ft_itoa((int)(1.0 / time_taken));
	mlx_string_put(cub->mlx, cub->win,
			cub->conf->res.x - (cub->conf->res.x / 8),
			cub->conf->res.y / 16, 255101, fps);
	free(fps);
	return (0);
}

static int	g_loop(t_win *cub)
{
	int upd;

	upd = 0;
	if (cub->keys.keyc[UP] && (upd = 1))
		up(&cub);
	else if (cub->keys.keyc[DOWN] && (upd = 1))
		down(&cub);
	if (cub->keys.keyc[LEFT] && (upd = 1))
		left(&cub);
	else if (cub->keys.keyc[RIGHT] && (upd = 1))
		right(&cub);
	if (cub->keys.keyc[R_UP] && (upd = 1))
		r_up(&cub);
	else if (cub->keys.keyc[R_DOWN] && (upd = 1))
		r_down(&cub);
	if (cub->keys.keyc[R_LEFT] && (upd = 1))
		r_left(&cub);
	else if (cub->keys.keyc[R_RIGHT] && (upd = 1))
		r_right(&cub);
	if (cub->keys.keyc[ESCAPE] && (upd = 1))
		escape(&cub);
	return (upd);
}

int		loop(t_win *cub)
{
	clock_t t;

	t = clock();
	cub->img = create_image(*cub);
	if (g_loop(cub))
	{
		update(cub);
		return (framer(t, cub));
	}
	return (0);
}
