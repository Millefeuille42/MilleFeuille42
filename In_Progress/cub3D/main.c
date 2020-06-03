/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 18:09:07 by mlabouri          #+#    #+#             */
/*   Updated: 2020/05/18 11:12:44 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

inline static void		disp_error(int err, t_conf *conf)
{
	ft_putstr_fd("Error\n", 2);
	if (err == -1)
		ft_putstr_fd("Invalid cub file!\n", 2);
	if (err == -10)
		ft_putstr_fd("Unknown file extension!\n", 2);
	if (err == -11)
		ft_putstr_fd("Incorrect number of arguments!\n", 2);
	if (err == -12)
		ft_putstr_fd("Unknown flag!\n", 2);
	if (err <= -20 && err >= -24)
		ft_putstr_fd("Invalid Configuration ", 2);
	if (err == -20)
		ft_putstr_fd("Resolution\n", 2);
	if (err == -21)
		ft_putstr_fd("Texture Path\n", 2);
	if (err == -22)
		ft_putstr_fd("Map\n", 2);
	if (err == -23)
		ft_putstr_fd("Color\n", 2);
	if (err == -24)
		ft_putstr_fd("Syntax\n", 2);
	if (err == -3)
		ft_putstr_fd("System Error\n", 2);
	deinit_conf(conf);
	exit(abs(err));
}

int						main(int argc, char *argv[])
{
	int		err;
	t_conf	conf;

	conf = (t_conf){.play.pos.x = -1, .play.dir = (t_dvec){1, 0}};
	conf.play.plan = (t_dvec){0, -0.66};
	if (argc < 1 || argc > 3 || argv[1] == NULL)
		disp_error(-11, &conf);
	else
	{
		if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".cub", 4))
			disp_error(-10, &conf);
		err = cub_parser(open(argv[1], O_RDONLY), &conf);
		if (argc == 3 && !ft_strncmp(argv[2], "--save", 7) && !err)
			save(&conf);
		else if (err || (argc == 3 && ft_strncmp(argv[2], "--save", 7)
		&& (err = -12)))
			disp_error(err, &conf);
		else
			graphics(&conf);
	}
	return (0);
}
