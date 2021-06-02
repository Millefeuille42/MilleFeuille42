/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 13:23:46 by mlabouri          #+#    #+#             */
/*   Updated: 2021/04/20 13:23:46 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	philo_sleep(t_philo *philo)
{
	philo_speak(philo, "is sleeping\n");
	philo_wait(philo->time_limits[SLEEP]);
	philo->state = THINK;
}

void	philo_eat(t_philo *philo)
{
	philo_speak(philo, "is eating\n");
	philo_wait(philo->time_limits[EAT]);
	sem_post(philo->sem_forks);
	sem_post(philo->sem_forks);
	if (philo->n_eat > 0)
		philo->n_eat--;
	philo->state = SLEEP;
}

void	philo_think(t_philo *philo)
{
	philo_speak(philo, "is thinking\n");
	philo->state = FORK;
}
