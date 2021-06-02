/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_setup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 13:23:54 by mlabouri          #+#    #+#             */
/*   Updated: 2021/04/20 13:23:54 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

static void	set_times(t_philo *philo, const t_param *args)
{
	philo->time_limits[DIED] = args->time_to_die;
	philo->time_limits[EAT] = args->time_to_eat;
	philo->time_limits[SLEEP] = args->time_to_sleep;
	philo->time_limits[FORK] = 0;
	philo->time_limits[THINK] = 0;
	philo->time_limits[STOP] = 0;
}

t_philo		philo_setup(const t_param *args, int id, sem_t *forks)
{
	t_philo	ret;

	ret.id = id + 1;
	ret.n_fork = args->n_philo;
	ret.n_eat = args->n_eat;
	ret.state = SLEEP;
	if (ret.id % 2 == 0)
		ret.state = FORK;
	ret.forks_taken = 0;
	set_times(&ret, args);
	ret.sem_forks = forks;
	return (ret);
}
