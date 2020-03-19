/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 10:30:08 by mlabouri          #+#    #+#             */
/*   Updated: 2020/03/08 10:30:08 by mlabouri         ###   ########          */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static char	ft_in_set(char const c, char const *set)
{
	size_t i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	size_t len;

	if (!s1 || *s1 == '\0')
		return (ft_strdup("\0"));
	if (!set || *set == '\0')
		return (ft_strdup(s1));
	while (ft_in_set(*s1, set))
		s1++;
	if (*s1 == '\0')
		return (ft_strdup("\0"));
	len = ft_strlen(s1) - 1;
	while (ft_in_set(s1[len], set))
		len--;
	return (ft_substr(s1, 0, len + 1));
}
