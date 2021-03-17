//
// Created by millefeuille on 2/22/21.
//

#include "../philo_one.h"

int		init_philos(t_app *app) {
	int p_num;
	int err;
	int i;

	p_num = app->params[philo_num];
	err = a_malloc((void **) &app->philos, sizeof(t_philo) * p_num);
	if (err)
		return (err);
	i = 0;
	while (i < p_num) {
		app->philos[i] = (t_philo) {
				.id = i, .last = 0, .status = thinking, .promise = 0,
				.speak_mutex = &app->speak_mutex,
		};
		app->philos[i].forks[0] = get_fork_by_id(app, i);
		app->philos[i].forks[1] = get_fork_by_id(app, p_num - 1);
		if (i)
			app->philos[i].forks[1] = get_fork_by_id(app, i - 1);
		i++;
	}
	app->philos[i - 1].last = 1;
	return (0);
}

static void    *philo_routine(void *arg) {
	char		dead;
	int			i;
	t_p_func	func_list[4];
	t_params	params;

	params = *((t_params *)arg);
//	printf("%d\n", params.philo->id);
	dead = 0;
	func_list[0] = philo_take_fork;
	func_list[1] = philo_eat;
	func_list[2] = philo_put_fork;
	func_list[3] = philo_sleep;
	i = 0;
	while (!dead) {
		dead = philo_do_promise(&params, func_list[i]);
		printf("\t//%d - %d//\n", dead, i);
		i = (i < 4) * (i + 1);
	}
	params.philo->status = ded;
	*params.stop = 1;
	return (NULL);
}

void			philo_start(t_app *app) {
	char		stop;
	int			i;
	t_params	params;

	params.conf[philo_num] = app->params[philo_num];
	params.conf[tt_die] = app->params[tt_die];
	params.conf[tt_eat] = app->params[tt_eat];
	params.conf[tt_sleep] = app->params[tt_sleep];
	params.conf[ts_eat] = app->params[ts_eat];
	stop = 0;
	params.stop = &stop;
	i = 0;
	params.philo = &app->philos[i];
	params.st_time = get_cur_time();
	pthread_create(&params.philo->thread_id, NULL, philo_routine, &params);

	//while (i < params.conf[philo_num]) {
	//	params.philo = &app->philos[i];
	//	params.st_time = get_cur_time();
	//	pthread_create(&params.philo->thread_id, NULL, philo_routine, &params);
	//	ft_milli_sleep(app->params[tt_eat]);
	//	i++;
	//}
	pthread_join(params.philo->thread_id, NULL);
}
