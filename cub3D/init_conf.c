/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_conf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 14:06:41 by mlabouri          #+#    #+#             */
/*   Updated: 2020/04/10 14:06:41 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	safe_free(void **element)
{
	if (element && *element)
		free(*element);
}

void	clear(char **pstr)
{
	int i;

	i = 0;
	if (pstr)
	{
		while (pstr[i])
		{
			free(pstr[i]);
			pstr[i] = NULL;
			i++;
		}
		free(pstr);
		pstr = NULL;
	}
}

static void	safe_close(int fd)
{
	if (fd)
		close(fd);
}

void deinit_conf(t_conf *conf)
{
	safe_free((void **)&(NORTH.path));
	safe_free((void **)&(SOUTH.path));
	safe_free((void **)&(WEST.path));
	safe_free((void **)&(EAST.path));
	safe_free((void **)&(SPRITE.path));
	clear(MAP);
	safe_close((NORTH.fd));
	safe_close((SOUTH.fd));
	safe_close((WEST.fd));
	safe_close((EAST.fd));
}