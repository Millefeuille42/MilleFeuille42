//
// Created by millefeuille on 2/22/21.
//

#include "../philo_one.h"

static void	*philo_do_wrapper(void *params) {
	t_params	*args;

	args = (t_params *)params;
	philo_take_fork(args);
	args->philo->promise = 0;
	//free(args);
	return (NULL);
}

void    	philo_speak(t_params *params, char *message) {
	pthread_mutex_lock(params->philo->death_mutex);
	if (!*params->stop)
		printf("%lums Philo %d %s\n", get_time_since(params->st_time), params->philo->id, message);
	pthread_mutex_unlock(params->philo->death_mutex);
}

char philo_do_promise(t_params *params) {
	pthread_t			thread_id;
	unsigned long		prom_time;
	unsigned long		tst;

	if (*params->stop)
		return (1);
	params->philo->promise = 1;
	pthread_create(&thread_id, NULL, philo_do_wrapper, params);
	pthread_detach(thread_id);
	tst = get_time_since(params->st_time);

	if (tst >= (unsigned long)params->conf[tt_die]) {
		return (1);
	}
	prom_time = params->conf[tt_die] - tst;
	ft_milli_sleep_interrupt(prom_time, &params->philo->promise);
	return ((char)(params->philo->promise || *params->stop));
}
