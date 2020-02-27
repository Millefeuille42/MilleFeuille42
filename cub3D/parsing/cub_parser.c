/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:34:45 by mlabouri          #+#    #+#             */
/*   Updated: 2020/02/27 17:45:34 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

#include <stdio.h>

static int leave_err(int err, void **t_free)
{
	if (t_free && *t_free)
		free(*t_free);
	return (err);
}

char	cub_parser(int fd, struct s_cub *conf)
{
	char	**line;
	char	des[2];
	char 	err;

	if ((err = (char)get_next_line(fd, &(line[0]))) != 1)
		return (err);
	if (designate(line[0], &des))
		return ((char)leave_err(-1, (void **)line[0]));
	if (includes(des))
		return ((char)leave_err(-1, (void **)line[0]));
	if ((line_r(line, des)))
	{
		free(line[0]);
		return ((char)leave_err(-1, (void **)line[1]));
	}
	free(line[0]);
	free(line[1]);
	return (1);
}