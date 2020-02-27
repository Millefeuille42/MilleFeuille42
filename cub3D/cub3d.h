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
};

char	cub_parser(int fd, struct s_cub *conf);
int		line_reader(char **line, int fd);

char		*ft_strdup(const char *s1);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
size_t		ft_strlen(const char *str);

#endif