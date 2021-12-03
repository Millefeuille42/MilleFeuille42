/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:32:33 by mlabouri          #+#    #+#             */
/*   Updated: 2021/12/03 13:32:33 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Mathieu LABOURIER on 25/07/2021.
//

#include "../so_long.h"

void	m_left(t_app *app)
{
	t_ivec	pos;

	pos = get_player_pos(app);
	pos.x--;
	if (pos.x <= 0)
		return ;
	edit_player_pos(app, pos);
}

void	m_down(t_app *app)
{
	t_ivec	pos;

	pos = get_player_pos(app);
	pos.y++;
	if (pos.y >= app->map.size)
		return ;
	edit_player_pos(app, pos);
}

void	m_right(t_app *app)
{
	t_ivec	pos;

	pos = get_player_pos(app);
	pos.x++;
	edit_player_pos(app, pos);
}

void	m_up(t_app *app)
{
	t_ivec	pos;

	pos = get_player_pos(app);
	pos.y--;
	if (pos.y <= 0)
		return ;
	edit_player_pos(app, pos);
}
