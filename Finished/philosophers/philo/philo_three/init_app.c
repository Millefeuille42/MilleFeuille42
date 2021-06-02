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

#include "philo_three.h"

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
			philos[i] = philo_setup(args, i, app->sem_forks);
			philos[i].sem_output = app->sem_output;
			philos[i].alive = &app->alive;
			i++;
		}
	}
	return (philos);
}

t_app					init_app(int argc, const char **argv)
{
	t_app	ret;
	t_param	args;

	ret.proper_init = 0;
	args = parse_args(argc, argv);
	sem_unlink("forks");
	ret.sem_forks = sem_open("forks", O_CREAT | O_EXCL, 0644, args.n_philo);
	if (!ret.sem_forks)
	{
		printf("Error:\nSEM FORK INIT\n");
		return (ret);
	}
	sem_unlink("output");
	ret.sem_output = sem_open("output", O_CREAT | O_EXCL, 0644, 1);
	if (!ret.sem_output)
	{
		printf("Error:\nSEM OUTPUT INIT\n");
		return (ret);
	}
	ret.alive = true;
	ret.n = args.n_philo;
	ret.philosophers = init_philos(&args, &ret);
	ret.proper_init = 1;
	return (ret);
}
