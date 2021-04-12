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
				.speak_mutex = &app->speak_mutex, .time_ate = 0, .death_mutex = &app->death_mutex,
		};
		app->philos[i].forks[0] = get_fork_by_id(app, i);
		app->philos[i].forks[1] = get_fork_by_id(app, (i + 1) % p_num);
		i++;
	}
	app->philos[i - 1].last = 1;
	return (0);
}

static void    *philo_routine(void *arg) {
	char		dead;
	int			i;
	t_c_func	func_list[5];
	t_params	*params;

	params = ((t_params *)arg);
	dead = 0;
	func_list[0] = philo_do_promise;
	func_list[1] = philo_eat;
	func_list[2] = philo_put_fork;
	func_list[3] = philo_sleep;
	func_list[4] = philo_think;
	i = 0;
	if (!((params->philo->id + 1) % 2))
		i = 3;
	while (*params->stop) {

	}
	params->st_time = get_cur_time();
	while (!dead && !*params->stop) {
		if (*params->stop)
			break ;
		if (params->philo->time_ate == params->conf[ts_eat] && i == 3) {
			break ;
		}
		dead = func_list[i](params);
		i = (i < 4) * (i + 1);
	}
	params->philo->status = ded;
	if ((params->philo->time_ate < params->conf[ts_eat] || params->conf[ts_eat] <= 0) && !*params->stop) {
		philo_speak(params, "is dead");
		pthread_mutex_lock(params->philo->death_mutex);
		*params->stop = 1;
		ft_milli_sleep(params->conf[tt_sleep] * 2);
		pthread_mutex_unlock(params->philo->death_mutex);
	}
	free(params);
	return (NULL);
}

void			philo_connard(t_params params) {
	t_params	*new_params;

	new_params = malloc(sizeof(t_params));
	*new_params = params;
	pthread_create(&new_params->philo->thread_id, NULL, philo_routine, new_params);
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
	stop = 1;
	i = 0;
	//i = params.conf[philo_num] - 5;
	while (i < params.conf[philo_num]) {
		params.philo = &app->philos[i];
		params.stop = &stop;
		philo_connard(params);
		i++;
	}
	printf("START\n\n");
	stop = 0;
	pthread_join(params.philo->thread_id, NULL);
}
