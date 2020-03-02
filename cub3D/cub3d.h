/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:34:39 by mlabouri          #+#    #+#             */
/*   Updated: 2020/03/02 17:26:16 by mlabouri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include "parsing/GNL/get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

#define RES conf->res
#define FLOOR conf->floor
#define ROOF conf->roof
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

typedef struct 		s_cub
{
	struct s_res	res;
	struct s_plan	floor;
	struct s_plan	roof;
	struct s_path	no;
	struct s_path	so;
	struct s_path	we;
	struct s_path	ea;
	struct s_path	sprite;
	char 			**map;
	char			pos;
}					t_cub;

int					cub_parser(int fd, struct s_cub *conf);

void				deinit_conf(struct s_cub *conf);
void				clear(char **pstr);

int					res_p(struct s_cub *conf, char *line);
int					plan_p(struct s_plan *plan, char *line);
int					path_p(char **path, char *line);
int					map_p(struct s_cub *conf, int fd);

int					res_e(struct s_res res);
int					rgb_e(struct s_plan plan);
int					map_e(char **map, char *pos);
int					path_e(struct s_path *file);

char				*ft_strdup(const char *s1);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strnstr(const char *hay, const char *ne, size_t len);
size_t				ft_strlen(const char *str);
int					ft_isdigit(int c);
int					atoi_mk2(const char *s, int start, int end);
char				ft_cinset(char c, const char *set);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				**ft_split(char const *s, char c);

#endif