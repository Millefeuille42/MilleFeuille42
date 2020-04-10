/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_conf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 14:06:41 by mlabouri          #+#    #+#             */
/*   Updated: 2020/04/10 15:35:41 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	safe_free(void **element)
{
	if (element && *element)
		free(*element);
}

void		clear(char **pstr)
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

void		deinit_conf(t_conf *conf)
{
	safe_free((void **)&(conf->no.path));
	safe_free((void **)&(conf->so.path));
	safe_free((void **)&(conf->we.path));
	safe_free((void **)&(conf->ea.path));
	safe_free((void **)&(conf->sprite.path));
	clear(conf->map);
	safe_close((conf->no.fd));
	safe_close((conf->so.fd));
	safe_close((conf->we.fd));
	safe_close((conf->ea.fd));
}
