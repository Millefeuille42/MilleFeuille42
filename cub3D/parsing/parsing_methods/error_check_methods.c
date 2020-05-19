/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_methods.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 14:06:41 by mlabouri          #+#    #+#             */
/*   Updated: 2020/05/18 11:12:45 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

int					res_e(struct s_res *res)
{
	if (res->x <= 0 || res->y <= 0)
		return (-2);
	return (0);
}

int					rgb_e(struct s_plan plan)
{
	if (plan.r > 255 || plan.g > 255 || plan.b > 255)
		return (-21);
	if (plan.r < 0 || plan.g < 0 || plan.b < 0)
		return (-2);
	return (0);
}

int					path_e(t_text *file)
{
	file->fd = open(file->path, O_RDONLY);
	if (file->fd < 0)
		return (-1);
	return (0);
}
