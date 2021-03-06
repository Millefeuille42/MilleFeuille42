/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 13:23:59 by mlabouri          #+#    #+#             */
/*   Updated: 2021/04/20 13:23:59 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (timeval_to_ms(&time));
}

void		philo_wait(int time)
{
	long	dest_time;

	dest_time = get_time() + time;
	while (get_time() < dest_time)
		usleep(1000);
}

int			get_timestamp(t_philo *philo)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (timeval_to_ms(&time) - timeval_to_ms(&philo->current_time));
}

void		philo_speak(t_philo *philo, char *message)
{
	int	timestamp;

	timestamp = get_timestamp(philo);
	pthread_mutex_lock(philo->output_lock);
	if (*philo->alive)
		printf("%d -- Philo %u %s", timestamp, philo->id, message);
	pthread_mutex_unlock(philo->output_lock);
}

void		philo_finish(t_philo *philo, t_state state)
{
	int	timestamp;

	philo->state = state;
	pthread_mutex_lock(philo->output_lock);
	timestamp = get_timestamp(philo);
	if (*philo->alive)
	{
		if (state == DIED)
		{
			printf("%d -- Philo %u %s", timestamp, philo->id, "has died\n");
			*philo->alive = false;
		}
		else if (state == STOP)
			printf("%d -- Philo %u %s", timestamp, philo->id, "has finished\n");
	}
	pthread_mutex_unlock(philo->output_lock);
}
