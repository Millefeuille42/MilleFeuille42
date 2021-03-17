//
// Created by millefeuille on 2/22/21.
//

#include "../philo_one.h"

static void	*philo_do_wrapper(void *params) {
	t_do_params	*args;

	args = (t_do_params *)params;
	args->func(args->params);
	args->params->philo->promise = 0;
	return (NULL);
}

void    	philo_speak(t_params *params, char *message) {
	if (*params->stop)
		return ;
	//pthread_mutex_lock(params->philo->speak_mutex);
	printf("\t%lu %d %s\n", get_time_since(params->st_time), params->philo->id, message);
	//pthread_mutex_unlock(params->philo->speak_mutex);
}

char		philo_do_promise(t_params *params, t_p_func func) {
	pthread_t	thread_id;
	long		prom_time;
	void		*args;

//	if (*params->stop)
//		return (1);
	args = &((t_do_params) {params, func});
	params->philo->promise = 1;
	pthread_create(&thread_id, NULL, philo_do_wrapper, args);
	pthread_detach(thread_id);
	if (func == philo_eat) {
		params->st_time = get_cur_time();
		printf("NEW TIME\n");
	}
	printf("||%lu ", get_time_since(params->st_time));
	prom_time = params->conf[tt_die] - get_time_since(params->st_time);
	printf("-- %lu||\n", prom_time);
	ft_milli_sleep_interrupt(prom_time, &params->philo->promise);
	return ((char)(params->philo->promise/* || *params->stop*/));
}