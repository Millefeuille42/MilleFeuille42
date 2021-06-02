/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 13:23:44 by mlabouri          #+#    #+#             */
/*   Updated: 2021/04/20 13:23:44 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static void	delete_app(t_app *app)
{
	int	i;

	if (app)
	{
		if (app->forks && app->philosophers)
		{
			i = 0;
			while (i < app->n)
			{
				pthread_mutex_destroy(&app->forks[i]);
				pthread_mutex_destroy(&app->philosophers->death_lock);
				i++;
			}
			free(app->forks);
			free(app->philosophers);
		}
		pthread_mutex_destroy(&app->output_lock);
	}
}

static void	start_controller(t_app *app)
{
	int	i;

	i = 0;
	while (i < app->n)
	{
		pthread_join(app->philosophers[i].thread, NULL);
		i++;
	}
	delete_app(app);
}

static void	start_philos(t_app *app)
{
	int		i;

	if (app)
	{
		i = 0;
		while (i < app->n)
		{
			philo_thread(&app->philosophers[i]);
			i++;
		}
	}
}

int			main(int argc, const char *argv[])
{
	t_app	app;

	if (!check_args(argc, argv))
	{
		printf("Invalid arguments");
		return (1);
	}
	app = init_app(argc, argv);
	start_philos(&app);
	start_controller(&app);
	return (0);
}
