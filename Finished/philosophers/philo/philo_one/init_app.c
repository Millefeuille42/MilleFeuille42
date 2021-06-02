/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_app.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 13:23:41 by mlabouri          #+#    #+#             */
/*   Updated: 2021/04/20 13:23:41 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static	t_philo			*init_philos(const t_param *args, t_app *app)
{
	int		i;
	t_philo	*philos;

	philos = (t_philo *)malloc(args->n_philo * sizeof(t_philo));
	if (philos)
	{
		i = 0;
		while (i < args->n_philo)
		{
			philos[i] = philo_setup(args, i, app->forks);
			philos[i].output_lock = &app->output_lock;
			philos[i].alive = &app->alive;
			i++;
		}
	}
	return (philos);
}

static	pthread_mutex_t	*init_forks(const t_param *args)
{
	int				i;
	pthread_mutex_t	*forks;

	forks = (pthread_mutex_t *)malloc(args->n_philo * sizeof(pthread_mutex_t));
	if (forks)
	{
		i = 0;
		while (i < args->n_philo)
		{
			pthread_mutex_init(&forks[i], NULL);
			i++;
		}
	}
	return (forks);
}

t_app					init_app(int argc, const char **argv)
{
	t_app	ret;
	t_param	args;

	args = parse_args(argc, argv);
	pthread_mutex_init(&ret.output_lock, NULL);
	pthread_mutex_lock(&ret.output_lock);
	pthread_mutex_unlock(&ret.output_lock);
	ret.alive = true;
	ret.n = args.n_philo;
	ret.forks = init_forks(&args);
	ret.philosophers = init_philos(&args, &ret);
	return (ret);
}
