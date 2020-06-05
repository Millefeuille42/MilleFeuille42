/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 15:58:05 by mlabouri          #+#    #+#             */
/*   Updated: 2020/05/18 11:12:45 by mlabouri         ###   ########.fr       */
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
			if (conf->map[i][i2] == '2' || conf->map[i][i2] == '3')
				count++;
			i2++;
		}
		i++;
	}
	count++;
	if (!(conf->buf = (double *)malloc(sizeof(double)
			* ((conf->res.x) * (conf->res.y)))))
		return (-3);
	return (count);
}

void				tag_sprite(t_ivec ray, t_sprite *sprites, char sp)
{
	int			i;
	t_sprite	*ret;

	i = 0;
	ret = NULL;
	while (!sprites[i].last && !ret)
	{
		if (ray.x == sprites[i].pos.x && ray.y == sprites[i].pos.y)
			ret = &sprites[i];
		i++;
	}
	if (ret)
	{
		ret->hit = 1;
		if (sp == '2')
			ret->tex = 1;
		else
			ret->tex = 2;
	}
}

int					sprites_init(t_conf *conf)
{
	int i;
	int i2;
	int count;

	i = 0;
	count = 0;
	if (!(conf->sp_list =
			(t_sprite *)malloc(sizeof(t_sprite) * count_sprites(conf))))
		return (-3);
	while (conf->map[i])
	{
		i2 = 0;
		while (conf->map[i][i2])
		{
			if (conf->map[i][i2] == '2' || conf->map[i][i2] == '3')
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
