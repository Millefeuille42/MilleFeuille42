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

static int leave_err(int err, void **t_free)
{
	if (t_free && *t_free)
		free(*t_free);
	return (err);
}

char	cub_parser(int fd, struct s_cub *conf)
{
	char **line;

	line_reader(line, fd);
	return (1);
}