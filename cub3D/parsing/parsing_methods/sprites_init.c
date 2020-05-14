/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 15:58:05 by mlabouri          #+#    #+#             */
/*   Updated: 2020/05/14 15:58:05 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

inline static int	count_sprites(t_conf *conf)
{
	int i;
	int i2;
	int count;

	i = 0;
	count = 0;
	while (conf->map[i])
	{
		i2 = 0;
		while (conf->map[i][i2])
		{
			if (conf->map[i][i2] == '2')
				count++;
			i2++;
		}
		i++;
	}
	count++;
	return (count);
}

int					sprites_init(t_conf *conf)
{
	int i;
	int i2;
	int count;

	i = 0;
	count = 0;
	if (!(conf->sp_list = malloc(sizeof(t_sprite) * count_sprites(conf))))
		return (-3);
	while (conf->map[i])
	{
		i2 = 0;
		while (conf->map[i][i2])
		{
			if (conf->map[i][i2] == '2')
			{
				conf->sp_list[count] = (t_sprite){.pos = {i2, i}, .last = 0};
				count++;
			}
			i2++;
		}
		i++;
	}
	conf->sp_list[count] = (t_sprite) {.last = 1};
	return (0);
}
