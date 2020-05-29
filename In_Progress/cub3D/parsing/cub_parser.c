/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 14:06:41 by mlabouri          #+#    #+#             */
/*   Updated: 2020/05/18 11:12:44 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

inline static int	leave_err(int err, void **t_free)
{
	if (t_free && *t_free)
		free(*t_free);
	return (err);
}

inline static int	parse_head(char *line)
{
	int			err;
	int			i;
	static char *charset[PARAMSNB] = {"R ", "NO", "SO", "EA",
									"WE", "S1", "F ", "C ", "S2"};

	i = 0;
	err = -2;
	while (i < PARAMSNB && err == -2)
	{
		if ((ft_strnstr(line + skip_wp(line), charset[i], 2)))
			err = i;
		else
			i++;
	}
	if (err == -2)
		return (-24);
	return (i);
}

inline static int	read_line(char *line, t_conf *conf, int head)
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
	if (head == 8 && (err = path_p(&conf->sprite_2.path, line)))
		return (err);
	return (0);
}

int					err_check(t_conf *conf)
{
	if ((res_e(&(conf->res))))
		return (-20);
	if ((rgb_e(conf->floor)))
		return (-23);
	if ((rgb_e(conf->roof)))
		return (-23);
	if ((map_e(conf->map, conf)))
		return (-22);
	if ((path_e(&conf->no)))
		return (-21);
	if ((path_e(&conf->so)))
		return (-21);
	if ((path_e(&conf->we)))
		return (-21);
	if ((path_e(&conf->ea)))
		return (-21);
	if ((path_e(&conf->sprite)))
		return (-21);
	if ((path_e(&conf->sprite_2)))
		return (-21);
	return (0);
}

int					cub_parser(int fd, t_conf *conf)
{
	int		i;
	int		head;
	char	*line;
	int		err;

	line = NULL;
	i = 0;
	while (i < PARAMSNB)
	{
		if ((head = get_next_line(fd, &line)) == -1)
			return (leave_err(head, (void **)&line));
		if (skip_wp(line) != (int)ft_strlen(line))
		{
			if ((head = parse_head(line + skip_wp(line))) < 0)
				return (leave_err(head, (void **)&line));
			if ((head = (read_line(line + skip_wp(line), conf, head))))
				return (leave_err(head, (void **)&line));
			i++;
		}
		free(line);
	}
	if ((err = error_route(fd, conf)))
		return (err);
	return (0);
}
