/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 17:45:41 by mlabouri          #+#    #+#             */
/*   Updated: 2020/02/27 17:46:03 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char designate(char *line, char *(des[2]))
{
	int i;

	i = 0;
	*(des[1]) = '\0';
	while (line[i] != ' ')
	{
		if (i > 1)
			return (1);
		*(des[i]) = line[i];
		i++;
	}
	return (0);
}

int line_r(char *line)
{
	int i;

	while (line[1][i]);
}