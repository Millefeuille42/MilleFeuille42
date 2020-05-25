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

inline static void		disp_error(int err)
{
	ft_putstr_fd("Error\n", 2);
	if (err == -1)
		ft_putstr_fd("Invalid cub file!\n", 2);
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
}

int						main(int argc, char *argv[])
{
	int		fd;
	int		err;
	t_conf	conf;

	if (argc < 1 || argc > 3)
		err = -1;
	else
	{
		conf = (t_conf){.play.pos.x = -1};
		conf.play.dir = (t_dvec){1, 0};
		conf.play.plan = (t_dvec){0, -0.66};
		fd = open(argv[1], O_RDONLY);
		err = cub_parser(fd, &conf);
		if (argc == 3 && !ft_strncmp(argv[2], "--save", 7) && !err)
			save(&conf);
		else if (!err)
			graphics(&conf);
		else
		{
			disp_error(err);
			deinit_conf(&conf);
		}
	}
	return (abs(err));
}
