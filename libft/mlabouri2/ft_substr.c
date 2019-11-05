/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 16:11:08 by mlabouri          #+#    #+#             */
/*   Updated: 2019/11/04 18:43:27 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_sub_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t j;

	j = 0;
	while (src[j] != '\0')
		j++;
	i = 0;
	while (src[i] != '\0' && i < dstsize)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (j);
}

char			*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub;

	if (!s || (unsigned int)ft_strlen(s) < start || len == 0)
	{
		sub = malloc(sizeof(char));
		if (!sub)
			return (NULL);
		sub[0] = '\0';
		return (sub);
	}
	i = 0;
	while (s[(size_t)start + i] != '\0' && i < len)
		i++;
	sub = malloc(sizeof(char) * i + 1);
	if (!sub)
		return (NULL);
	ft_sub_strlcpy(sub, s + start, len);
	return (sub);
}
