//
// Created by millefeuille on 2/22/21.
//

#include "philo_one.h"

void	init_app(t_app *app, int argc, char *args[]) {
	app->params[ts_eat] = 0;
	app->params[philo_num] = ft_atoi(args[1]);
	app->params[tt_die] = ft_atoi(args[2]);
	app->params[tt_eat] = ft_atoi(args[3]);

	app->params[tt_sleep] = ft_atoi(args[4]);
	if (argc == 6)
		app->params[ts_eat] = ft_atoi(args[5]);
	if (app->params[ts_eat] == 0)
		app->params[ts_eat] = -1;
	pthread_mutex_init(&app->speak_mutex, NULL);
	pthread_mutex_init(&app->death_mutex, NULL);
	init_forks(app);
	init_philos(app);
}

void	end_app(t_app *app) {
	pthread_mutex_destroy(&app->speak_mutex);
	pthread_mutex_destroy(&app->death_mutex);
	destroy_forks(app);
	free(app->philos);
}

int		main(int argc, char *argv[]) {
	t_app	app;

	if (argc < 4 || argc > 6) {
		printf("Invalid number of arguments\n");
		return (2);
	}
	init_app(&app, argc, argv);
	philo_start(&app);
	end_app(&app);
}