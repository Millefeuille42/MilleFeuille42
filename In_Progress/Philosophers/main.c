//
// Created by millefeuille on 2/12/21.
//

#include "philosophers.h"

int		a_malloc(void **ptr, size_t size) {
	*ptr = malloc(size);
	if (!*ptr)
		return (1);
	return (0);
}

int		get_fork_by_id(t_app app, t_fork *fork, int id) {
	int i;

}

int		init_forks(t_app *app, int fork_num) {
	int	i;
	int	err;

	err = a_malloc((void **) &app->forks, sizeof(t_fork) * fork_num);
	if (err)
		return (err);
	i = 0;
	while (i < fork_num) {
		app->forks[i] = (t_fork) {.id = i, .last = 0};
		pthread_mutex_init(&app->forks[i].mutex, NULL);
		i++;
	}
	app->forks[i].last = 1;
	return (0);
}

int		init_philos(t_app *app, int philo_num) {
	int	i;
	int	err;

	err = a_malloc((void **) &app->philos, sizeof(t_fork) * philo_num);
	if (err)
		return (err);
	i = 0;
	while (i < philo_num) {
		app->philos[i] = (t_philo) {.id = i, .last = 0};
		pthread_mutex_init(&app->philos[i].mutex, NULL);
		i++;
	}
	return (0);
}

int		main(int argc, char*argv[]) {
	if (argc < 4 || argc > 6) {
		printf("Invalid number of arguments\n");
	 }

	init_philo()
	return (0);
}