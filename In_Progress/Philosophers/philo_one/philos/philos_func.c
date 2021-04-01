//
// Created by millefeuille on 23/02/2021.
//

#include "../philo_one.h"

char	philo_eat(t_params *params) {
	char				die;
	unsigned long		prom_time;
	unsigned long		tst;

	if (*params->stop)
		return (1);
	params->st_time = get_cur_time();
	tst = get_time_since(params->st_time);
	if (tst >= (unsigned long)params->conf[tt_die]) {
		return (1);
	}
	prom_time = params->conf[tt_die] - tst;
	die = (char)((unsigned long)params->conf[tt_eat] > prom_time);
	if (!die)
		prom_time = params->conf[tt_sleep];
	params->philo->time_ate++;
	params->philo->status = eating;
	philo_speak(params, "is eating");
	ft_milli_sleep(prom_time);
	return (die);
}

char	philo_think(t_params *params) {
//	unsigned long		tst;

//	tst = get_time_since(params->st_time);
//	if (tst >= (unsigned long)params->conf[tt_die]) {
//		return (1);
//	}	params->philo->status = thinking;
	philo_speak(params, "is thinking");
	return (0);
}

char	philo_sleep(t_params *params) {
	char				die;
	unsigned long		prom_time;
	unsigned long		tst;

	if (*params->stop)
		return (1);
	tst = get_time_since(params->st_time);
	if (tst >= (unsigned long)params->conf[tt_die]) {
		return (1);
	}
	prom_time = params->conf[tt_die] - tst;
	die = (char)((unsigned long)params->conf[tt_sleep] > prom_time);
	if (!die)
		prom_time = params->conf[tt_sleep];
	params->philo->status = sleeping;
	philo_speak(params, "is sleeping");
	ft_milli_sleep(prom_time);
	return (die);
}

void	philo_take_fork(t_params *params) {
	int		i;
	t_philo *philo;

	philo = params->philo;
	philo->status = thinking;
	i = 0;
	while (i < 2) {
		pthread_mutex_lock(&philo->forks[i]->mutex);
		philo_speak(params, "has taken a fork");
		i++;
	}
}

char	philo_put_fork(t_params *params) {
	int		i;
	t_philo *philo;

	philo = params->philo;
	i = 0;
	while (i < 2) {
		philo_speak(params, "has dropped a fork");
		pthread_mutex_unlock(&philo->forks[i]->mutex);
		i++;
	}
	return (0);
}