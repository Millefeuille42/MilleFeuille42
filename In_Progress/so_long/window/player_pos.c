/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:32:38 by mlabouri          #+#    #+#             */
/*   Updated: 2021/12/03 13:32:38 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Mathieu LABOURIER on 25/07/2021.
//

#include "../so_long.h"

inline static void	erase_player_pos(t_app *app)
{
	int			i;
	int			i2;
	t_element	*cur;

	i = 0;
	cur = app->map.start;
	while (cur)
	{
		i2 = 0;
		while (((char *)cur->data)[i2])
		{
			if (((char *)cur->data)[i2] == 'P')
			{
				((char *)cur->data)[i2] = '0';
				return ;
			}
			i2++;
		}
		cur = cur->next;
		i++;
	}
}

inline static void	decide_action(t_app *app, t_element *cur, int i)
{
	if (((char *)cur->data)[i] != '1')
	{
		app->mov_num++;
		ft_putnbr_fd(app->mov_num, 1);
		ft_putstr_fd("\n", 1);
		if (((char *)cur->data)[i] == 'C')
			app->set[0]--;
		if (((char *)cur->data)[i] == 'E')
		{
			if (app->set[0] == 0)
			{
				ft_putstr_fd("YOU WIN!\n", 1);
				quit(app);
			}
			return ;
		}
		erase_player_pos(app);
		(((char *)cur->data)[i]) = 'P';
		return ;
	}
}

t_ivec	get_player_pos(t_app *app)
{
	int			i;
	int			i2;
	t_element	*cur;

	i = 0;
	cur = app->map.start;
	while (cur)
	{
		i2 = 0;
		while (((char *)cur->data)[i2])
		{
			if (((char *)cur->data)[i2] == 'P')
				return ((t_ivec){i2, i});
			i2++;
		}
		cur = cur->next;
		i++;
	}
	return ((t_ivec){0, 0});
}

void	edit_player_pos(t_app *app, t_ivec dest)
{
	int			i;
	int			i2;
	t_element	*cur;

	i = 0;
	cur = app->map.start;
	while (cur)
	{
		i2 = 0;
		while (((char *)cur->data)[i2])
		{
			if (dest.x >= (int)ft_strlen(cur->data))
				return ;
			if (i2 == dest.x && i == dest.y)
				decide_action(app, cur, i2);
			i2++;
		}
		cur = cur->next;
		i++;
	}
}
