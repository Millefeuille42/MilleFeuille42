/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 14:06:41 by mlabouri          #+#    #+#             */
/*   Updated: 2020/05/14 15:58:06 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

inline static size_t	ft_sub_strlcpy(char *dst, const char *src, size_t dsize)
{
	size_t i;
	size_t j;

	j = 0;
	while (src[j] != '\0')
		j++;
	i = 0;
	while (src[i] != '\0' && i < dsize)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (j);
}

char					*ft_substr(char const *s, unsigned int strt, size_t len)
{
	size_t	i;
	char	*sub;

	if (!s || len == 0 || (unsigned int)ft_strlen(s) <= strt)
		return (ft_strdup("\0"));
	i = 0;
	while (s[(size_t)strt + i] != '\0' && i < len)
		i++;
	sub = malloc(sizeof(char) * i + 1);
	if (!sub)
		return (NULL);
	ft_sub_strlcpy(sub, s + strt, len);
	return (sub);
}
