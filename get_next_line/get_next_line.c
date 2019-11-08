/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 16:14:23 by mlabouri          #+#    #+#             */
/*   Updated: 2019/11/04 18:25:18 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_gnl_line(size_t rsize, char *buf, char **str, size_t *i)
{
	*i = 0;
	if (rsize == 0)
		return (2);
	if (rsize < 0)
		return (100);
	while (buf[*i] != '\n' && *i < rsize)
		*i = *i + 1;
	if (!*str)
		*str = ft_substr(buf, 0, *i);
	else
		*str = ft_strjoin_gnl(*str, buf, *i);
	if (!*str)
		return (100);
	if (buf[*i] == '\n' && *i < rsize)
	{
		buf[rsize + 1] = '\0';
		return (-1);
	}
	if (buf[*i] == '\n' && *i == rsize)
		return (1);
	return (0);
}
