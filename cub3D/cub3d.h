/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 10:30:08 by mlabouri          #+#    #+#             */
/*   Updated: 2020/03/12 18:04:33 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <math.h>
#include <time.h>
#include <stdio.h> //remove
#include <mlx.h>

#define NORTH conf->no
#define SOUTH conf->so
#define WEST conf->we
#define EAST conf->ea
#define SPRITE conf->sprite
#define MAP conf->map
#define PARAMSNB 8

typedef struct 		s_res
{
	int				x;
	int 			y;
}					t_res;

typedef struct 		s_plan
{
	int				r;
	int 			g;
	int 			b;
}					t_plan;

typedef struct		s_path
{
	char			*path;
	int				fd;
}					t_path;

typedef struct 		s_dbl_co
{
	double			x;
	double			y;
}					t_dbl_co;

typedef struct 		s_int_co
{
	int				x;
	int				y;
}					t_int_co;

typedef struct		s_conf
{
	t_res			res;
	t_plan			floor;
	t_plan			roof;
	t_path			no;
	t_path			so;
	t_path			we;
	t_path			ea;
	t_path			sprite;
	char 			**map;
	t_dbl_co		pos;
	double 			dir_a;
	double 			fov;
}					t_conf;

int					cub_parser(int fd, t_conf *conf);

void				deinit_conf(t_conf *conf);

#endif