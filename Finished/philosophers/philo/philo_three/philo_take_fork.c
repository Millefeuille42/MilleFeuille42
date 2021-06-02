/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_take_fork.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 13:23:56 by mlabouri          #+#    #+#             */
/*   Updated: 2021/04/20 13:23:56 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

static void	*check_time(void *philo)
{
	t_philo *p;

	p = (t_philo *)philo;
	while (p->forks_taken != 2)
	{
		if (get_timestamp(p) > p->time_limits[DIED])
		{
			philo_finish(p, DIED);
			return (NULL);
		}
		philo_wait(1);
	}
	return (NULL);
}

static void	take_forks(t_philo *philo)
{
	pthread_t	thread;

	philo->forks_taken = 0;
	pthread_create(&thread, NULL, check_time, philo);
	pthread_detach(thread);
	sem_wait(philo->sem_forks);
	philo_speak(philo, "has taken a fork\n");
	sem_wait(philo->sem_forks);
	philo_speak(philo, "has taken a fork\n");
	philo->forks_taken = 2;
}

void		philo_take_forks(t_philo *philo)
{
	long	time_left;

	if (philo->n_fork > 1)
	{
		take_forks(philo);
		philo->state = EAT;
		gettimeofday(&philo->current_time, NULL);
	}
	else
	{
		time_left = philo->time_limits[DIED] - get_timestamp(philo);
		philo_wait(time_left);
		philo_finish(philo, DIED);
	}
}
