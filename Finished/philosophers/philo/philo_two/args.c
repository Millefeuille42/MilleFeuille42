/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 13:23:37 by mlabouri          #+#    #+#             */
/*   Updated: 2021/04/20 13:23:37 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

t_param	parse_args(int argc, const char **argv)
{
	t_param	ret;

	ret.n_philo = ft_atoi(argv[1]);
	ret.time_to_die = ft_atoi(argv[2]);
	ret.time_to_eat = ft_atoi(argv[3]);
	ret.time_to_sleep = ft_atoi(argv[4]);
	ret.n_eat = -1;
	if (argc == 6)
		ret.n_eat = ft_atoi(argv[5]);
	return (ret);
}

t_bool	check_args(int argc, const char **argv)
{
	int i;

	if (argc >= 5)
	{
		i = 1;
		while (i < argc)
		{
			if (!ft_isnum(argv[i]))
				return (false);
			i++;
		}
		return (true);
	}
	return (false);
}
