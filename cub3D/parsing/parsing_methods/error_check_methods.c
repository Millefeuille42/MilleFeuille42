/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_methods.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 10:30:08 by mlabouri          #+#    #+#             */
/*   Updated: 2020/03/09 15:44:52 by mlabouri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

int res_e(struct s_res res)
{
	// TODO
	//		- MiniLibX Resolution

	if (res.x <= 0 || res.y <= 0)
		return (-2);
	return (0);
}

int rgb_e(struct s_plan plan)
{
	if (plan.r > 255 || plan.g > 255 || plan.b > 255)
		return (-2);
	return (0);
}

int path_e(struct s_path *file)
{
	int fd;

	fd = open(file->path, O_RDONLY);
	if (fd < 0)
		return (-1);
	return (0);
}