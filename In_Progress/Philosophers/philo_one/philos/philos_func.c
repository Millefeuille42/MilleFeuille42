//
// Created by millefeuille on 23/02/2021.
//

#include "../philo_one.h"

void	philo_eat(t_params *params) {
	params->philo->status = eating;
	philo_speak(params, "is eating");
	ft_milli_sleep(params->conf[tt_eat]);
}

void	philo_sleep(t_params *params) {
	params->philo->status = sleeping;
	philo_speak(params, "is sleeping");
	ft_milli_sleep(params->conf[tt_sleep]);
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

void	philo_put_fork(t_params *params) {
	int		i;
	t_philo *philo;

	philo = params->philo;
	i = 0;
	while (i < 2) {
		philo_speak(params, "has dropped a fork");
		pthread_mutex_unlock(&philo->forks[i]->mutex);
		i++;
	}
}