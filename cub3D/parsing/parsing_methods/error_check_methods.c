/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_methods.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 14:06:41 by mlabouri          #+#    #+#             */
/*   Updated: 2020/04/13 11:09:28 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

int	res_e(struct s_res *res)
{
	if (res->x <= 0 || res->y <= 0)
		return (-2);
	res->x = res->x > 1920 ? 1920 : res->x;
	res->y = res->y > 1080 ? 1080 : res->y;
	return (0);
}

int	rgb_e(struct s_plan plan)
{
	if (plan.r > 255 || plan.g > 255 || plan.b > 255)
		return (-21);
	if (plan.r < 0 || plan.g < 0 || plan.b < 0)
		return (-2);
	return (0);
}

static int texture_length(t_text *text)
{
	char *line;
	char flag;

	flag = 0;
	while (get_next_line(text->fd, &line))
	{
		if (flag)
		{
			if (line[ft_strlen(line) - 1] == ',')
				line[ft_strlen(line) - 1] = '\0';
			else
				flag = 0;
			text->size.x = (int)ft_strlen(line) - 2;
			text->size.y++;
		}
		if (!ft_strncmp(line, "/* pixels */", ft_strlen("/* pixels */")))
			flag = 1;
		free(line);
	}
}

int	path_e(t_text *file)
{
	file->fd = open(file->path, O_RDONLY);
	if (file->fd < 0)
		return (-1);
	texture_length(file);
	return (0);
}
