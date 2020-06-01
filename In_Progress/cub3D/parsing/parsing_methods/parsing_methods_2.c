/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_methods_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 14:06:41 by mlabouri          #+#    #+#             */
/*   Updated: 2020/05/18 11:12:45 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

inline static int	rgb_parsing(int *color, int *i, char *line, char *pos)
{
	int i2;

	i2 = *i;
	if (!(ft_isdigit(line[i2])))
		return (-23);
	while (ft_isdigit(line[i2]))
		i2++;
	if (!(ft_cinset(line[i2], pos)) && line[i2] != '\0')
		return (-23);
	*color = atoi_mk2(line, *i, i2 - 1);
	*i = i2;
	while (ft_cinset(line[*i], pos))
		*i = *i + 1;
	return (0);
}

int					plan_p(struct s_plan *plan, char *line)
{
	int i;

	i = 2;
	if (!ft_cinset(line[i], "\n\r\t\v\f ") && !(ft_isdigit(line[i])))
		return (-23);
	while (ft_cinset(line[i], "\n\r\t\v\f ") && line[i])
		i++;
	if (rgb_parsing(&(plan->r), &i, line, "\n\r\t\v\f ,"))
		return (-23);
	if (rgb_parsing(&(plan->g), &i, line, "\n\r\t\v\f ,"))
		return (-23);
	if (rgb_parsing(&(plan->b), &i, line, "\n\r\t\v\f "))
		return (-23);
	return (0);
}

int					skip_wp(char *str)
{
	int i;

	i = 0;
	while (str[i] && ft_cinset(str[i], "\n\r\t\v\f "))
		i++;
	return (i);
}
