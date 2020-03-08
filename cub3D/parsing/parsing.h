/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 10:30:08 by mlabouri          #+#    #+#             */
/*   Updated: 2020/03/08 10:30:08 by mlabouri         ###   ########          */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

#include "../cub3d.h"
#include "GNL/get_next_line.h"

int					res_p(t_conf *conf, char *line);
int					plan_p(t_plan *plan, char *line);
int					path_p(char **path, char *line);
int					map_p(t_conf *conf, int fd);

int					res_e(t_res res);
int					rgb_e(t_plan plan);
int					map_e(char **map, t_dbl_co *pos);
int					path_e(t_path *file);

char				*ft_strdup(const char *s1);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strnstr(const char *hay, const char *ne, size_t len);
size_t				ft_strlen(const char *str);
int					ft_isdigit(int c);
int					atoi_mk2(const char *s, int start, int end);
char				ft_cinset(char c, const char *set);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				**ft_split(char const *s, char c);

void				clear(char **pstr);
# endif
