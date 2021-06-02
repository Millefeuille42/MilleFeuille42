/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 13:23:49 by mlabouri          #+#    #+#             */
/*   Updated: 2021/04/20 13:23:49 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

static void	philo_action(t_philo *philo, void (*action)(t_philo *))
{
	long	timestamp;
	long	time_left;

	timestamp = get_timestamp(philo);
	if (timestamp > philo->time_limits[DIED])
	{
		philo_finish(philo, DIED);
		return ;
	}
	if (philo->n_eat == 0)
	{
		philo_finish(philo, STOP);
		return ;
	}
	time_left = get_timestamp(philo) + philo->time_limits[philo->state];
	if (time_left > philo->time_limits[DIED])
	{
		philo_wait(philo->time_limits[DIED] - timestamp);
		philo_finish(philo, DIED);
		return ;
	}
	action(philo);
}

static char	philo_do(t_philo *philo)
{
	static const t_actions	actions[4] = {
		philo_think,
		philo_take_forks,
		philo_eat,
		philo_sleep,
	};

	gettimeofday(&philo->current_time, NULL);
	while (philo->state != DIED && philo->state != STOP && *philo->alive)
		philo_action(philo, actions[philo->state]);
	sem_post(philo->sem_forks);
	sem_post(philo->sem_forks);
	if (*philo->alive)
		return (2);
	return (0);
}

void		philo_thread(t_philo *philo, t_app *app)
{
	philo->process_id = fork();
	if (philo->process_id == 0)
		exit(philo_do(philo));
	else if (philo->process_id < 0)
	{
		printf("Error:\nForking\n");
		delete_app(app);
		exit(-1);
	}
}
