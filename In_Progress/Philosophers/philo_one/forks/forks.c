//
// Created by millefeuille on 2/22/21.
//

#include "../philo_one.h"

t_fork		*get_fork_by_id(t_app *app, int id) {
	int i;

	i = 0;
	while (i < app->params[philo_num]) {
		if (app->forks[i].id == id) {
			return (&app->forks[i]);
		}
		if (app->forks[i].last)
			break ;
		i++;
	}
	return (NULL);
}

void	destroy_forks(t_app *app) {
	int	i;

	i = 0;
	while (i < app->params[philo_num]) {
		pthread_mutex_destroy(&app->forks[i].mutex);
		i++;
	}
	free(app->forks);
}

int			init_forks(t_app *app) {
	int f_num;
	int err;
	int i;

	f_num = app->params[philo_num];
	err = a_malloc((void **) &app->forks, sizeof(t_fork) * f_num);
	if (err)
		return (err);
	i = 0;
	while (i < f_num) {
		app->forks[i] = (t_fork) {
				.id = i, .last = 0, .status = 0,
		};
		pthread_mutex_init(&app->forks[i].mutex, NULL);
		i++;
	}
	app->forks[i - 1].last = 1;
	return (0);
}