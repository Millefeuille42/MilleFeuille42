/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_methods.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 14:06:41 by mlabouri          #+#    #+#             */
/*   Updated: 2020/05/14 15:58:05 by mlabouri         ###   ########.fr       */
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

inline static int	parse_size(char *str, int *i)
{
	char	size[8];
	int		i2;

	i2 = 0;
	while (ft_isdigit(str[*i]))
	{
		size[i2] = str[*i];
		*i += 1;
		i2++;
	}
	size[i2] = '\0';
	return (ft_atoi(size));
}

inline static void	texture_length(t_text *text)
{
	char	*line;
	int		i;

	i = 0;
	while (i < 3)
	{
		get_next_line(text->fd, &line);
		free(line);
		i++;
	}
	get_next_line(text->fd, &line);
	i = 0;
	while (!ft_isdigit(line[i]))
		i++;
	text->s.x = parse_size(line, &i);
	while (!ft_isdigit(line[i]))
		i++;
	text->s.y = parse_size(line, &i);
	free(line);
}

int					path_e(t_text *file)
{
	file->fd = open(file->path, O_RDONLY);
	if (file->fd < 0)
		return (-1);
	texture_length(file);
	return (0);
}
