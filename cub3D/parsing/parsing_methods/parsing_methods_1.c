/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_methods_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 10:30:08 by mlabouri          #+#    #+#             */
/*   Updated: 2020/03/09 15:44:52 by mlabouri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

int	res_p(t_conf *conf, char *line)
{
	int i;
	int i2;

	i = 2;
	if (line[i] != ' ' && !(ft_isdigit(line[i])))
		return (-2);
	while (line[i] == ' ' && line[i])
		i++;
	i2 = i;
	while (ft_isdigit(line[i2]))
		i2++;
	if (line[i2] != ' ')
		return (-2);
	conf->res.x = atoi_mk2(line, i, i2 - 1);
	i = i2;
	while (line[i] == ' ' && line[i])
		i++;
	i2 = i;
	while (ft_isdigit(line[i2]))
		i2++;
	if (!(ft_cinset(line[i2], " \n\t\r")) && line[i2] != '\0')
		return (-2);
	conf->res.y = atoi_mk2(line, i, i2 -1);
	return (0);
}

int		path_p(char **path, char *line)
{
	int i;

	i = 2;
	while (line[i] == ' ' && line[i])
		i++;
	if (!(*path = ft_substr(line, i, 2147483647)))
		return (-3);
	return (0);
}