/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 14:06:41 by mlabouri          #+#    #+#             */
/*   Updated: 2020/04/10 14:06:41 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

#include "../cub3d.h"
#include "GNL/get_next_line.h"

typedef struct		s_map_prop
{
	int				x;
	int				y;
	int				length;
	int				lines;
}					t_map_prop;

int					res_p(t_conf *conf, char *line);
int					plan_p(t_plan *plan, char *line);
int					path_p(char **path, char *line);
int					map_p(t_conf *conf, int fd);

int					res_e(t_res *res);
int					rgb_e(t_plan plan);
int					map_e(char **map, t_conf *conf);
int					path_e(t_path *file);

void				clear(char **pstr);
# endif
