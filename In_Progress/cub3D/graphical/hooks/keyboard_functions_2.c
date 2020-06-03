/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_functions_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 14:06:41 by mlabouri          #+#    #+#             */
/*   Updated: 2020/05/18 11:12:44 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/graphical.h"

void	r_left(t_win **cub)
{
	rotate_2(&(*cub)->conf->play.dir, &(*cub)->conf->play.plan,
			15 * ((1.0 / FPS) * ROT));
}

void	r_right(t_win **cub)
{
	rotate_2(&(*cub)->conf->play.dir, &(*cub)->conf->play.plan,
			-15 * ((1.0 / FPS) * ROT));
}

void	r_up(t_win **cub)
{
	if ((*cub)->inc_u < 100)
		(*cub)->inc_u += (int)((1.0 / FPS) * (ROT + 2025));
	if ((*cub)->inc_d < 100)
		(*cub)->inc_d += (int)((1.0 / FPS) * (ROT + 2025));
}

void	r_down(t_win **cub)
{
	if ((*cub)->inc_u > -100)
		(*cub)->inc_u -= (int)((1.0 / FPS) * (ROT + 2025));
	if ((*cub)->inc_d > -100)
		(*cub)->inc_d -= (int)((1.0 / FPS) * (ROT + 2025));
}
