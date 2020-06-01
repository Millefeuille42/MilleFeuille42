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

int		loop(t_win *cub)
{
	clock_t t;

	t = clock();
	cub->img = create_image(*cub);
	if (cub->keys.keyc[UP])
		up(&cub);
	else if (cub->keys.keyc[DOWN])
		down(&cub);
	if (cub->keys.keyc[LEFT])
		left(&cub);
	else if (cub->keys.keyc[RIGHT])
		right(&cub);
	if (cub->keys.keyc[R_UP])
		r_up(&cub);
	else if (cub->keys.keyc[R_DOWN])
		r_down(&cub);
	if (cub->keys.keyc[R_LEFT])
		r_left(&cub);
	else if (cub->keys.keyc[R_RIGHT])
		r_right(&cub);
	if (cub->keys.keyc[ESCAPE])
		escape(&cub);
	update(cub);
	return (framer(t, cub));
}
