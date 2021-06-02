/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timeval_to_ms.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 13:24:01 by mlabouri          #+#    #+#             */
/*   Updated: 2021/04/20 13:24:01 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

long	timeval_to_ms(struct timeval *time)
{
	return ((long)(time->tv_usec * 0.001 + (double)time->tv_sec * 1000));
}
