/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 12:02:26 by mlabouri          #+#    #+#             */
/*   Updated: 2019/10/18 16:28:54 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub;

	i = 0;
	while (s[(size_t)start + i] != '\0' && i < len)
		i++;
	sub = malloc(sizeof(char) * i + 1);
	if (!sub)
		return (NULL);
	i = 0;
	while (s[(size_t)start + i] != '\0' && i < len)
	{
		sub[i] = s[(size_t)start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*ft_strjoin_limit(char *s1, char *s2, size_t len)
{
	size_t	i;
	size_t	i2;
	char	*join;

	i = 0;
	i2 = 0;
	if (!(join = malloc(sizeof(char) * (ft_strlen(s1) + len + 1))))
		return (NULL);
	while (s1[i] != '\0')
	{
		join[i] = s1[i];
		i++;
	}
	while (s2[i2] != '\0' && i2 < len)
	{
		join[i + i2] = s2[i2];
		i2++;
	}
	join[i + i2] = '\0';
	free((void *)s1);
	return (join);
}
