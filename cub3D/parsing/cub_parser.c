/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 10:30:08 by mlabouri          #+#    #+#             */
/*   Updated: 2020/03/25 22:25:42 by millefeuille     ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	leave_err(int err, void **t_free)
{
	if (t_free && *t_free)
		free(*t_free);
	return (err);
}

static int	parse_head(char *line)
{
	int err;
	int i;
	static char *charset[PARAMSNB];

	i = 0;
	err = -2;
	charset[0] = "R ";
	charset[1] = "NO";
	charset[2] = "SO";
	charset[3] = "WE";
	charset[4] = "EA";
	charset[5] = "S ";
	charset[6] = "F ";
	charset[7] = "C ";
	while (i < PARAMSNB && err == -2)
	{
		if ((ft_strnstr(line, charset[i], 2)))
			err = i;
		else
			i++;
	}
	if (err == -2)
		return (-2);
	return (i);
}

static int	read_line(char *line, t_conf *conf, int head)
{
	int err;

	if (head == 0 && (err = res_p(conf, line)))
		return (err);
	if (head == 1 && (err = path_p(&conf->no.path, line)))
		return (err);
	if (head == 2 && (err = path_p(&conf->so.path, line)))
		return (err);
	if (head == 3 && (err = path_p(&conf->we.path, line)))
		return (err);
	if (head == 4 && (err = path_p(&conf->ea.path, line)))
		return (err);
	if (head == 5 && (err = path_p(&conf->sprite.path, line)))
		return (err);
	if (head == 6 && (err = plan_p(&conf->floor, line)))
		return (err);
	if (head == 7 && (err = plan_p(&conf->roof, line)))
		return (err);
	return (0);
}

static int	err_check(t_conf *conf)
{
	if ((res_e(conf->res)))
		return (-2);
	if ((rgb_e(conf->floor)))
		return (-2);
	if ((rgb_e(conf->roof)))
		return (-2);
	if ((map_e(conf->map, conf)))
		return (-2);
	if ((path_e(&conf->no)))
		return (-1);
	if ((path_e(&conf->so)))
		return (-1);
	if ((path_e(&conf->we)))
		return (-1);
	if ((path_e(&conf->ea)))
		return (-1);
	if ((path_e(&conf->sprite)))
		return (-1);
	return (0);
}

int			cub_parser(int fd, t_conf *conf)
{
	int i;

	int head;
	char *line;

	line = NULL;
	i = 0;
	while (i < PARAMSNB)
	{
		if ((head = get_next_line(fd, &line)) == -1)
			return (leave_err(head, (void **)&line));
		if ((head = parse_head(line)) < 0)
			return (leave_err(head, (void **)&line));
		if ((head = (read_line(line, conf, head))))
			return (leave_err(head, (void **)&line));
		i++;
		free(line);
	}
	if ((map_p(conf, fd)) || ((err_check(conf))))
		return (-2);
	return (0);
}