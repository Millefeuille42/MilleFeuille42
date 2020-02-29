/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:34:39 by mlabouri          #+#    #+#             */
/*   Updated: 2020/02/27 17:19:53 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include "parsing/GNL/get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

#define FLAGLEN 8

struct 				s_res
{
	int				x;
	int 			y;
};

struct 				s_plan
{
	int				r;
	int 			g;
	int 			b;
};

struct 				s_cub
{
	struct s_res	res;
	struct s_plan	floor;
	struct s_plan	roof;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char 			*map;
	int				(*parse[7])(char *);
};

char				cub_parser(int fd, struct s_cub *conf);
int					line_reader(int fd);
int					res_p(struct s_cub *conf, char *line);

int					map_p(struct s_cub *conf, int fd);

int					res_e(struct s_res res);
int					rgb_e(struct s_plan plan);
int					map_e(char *map);

char				*ft_strdup(const char *s1);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strnstr(const char *hay, const char *n, size_t len);
size_t				ft_strlen(const char *str);
int					ft_isdigit(int c);
int					atoi_mk2(const char *s, int start, int end);
char				ft_cinset(char c, const char *set);

#endif