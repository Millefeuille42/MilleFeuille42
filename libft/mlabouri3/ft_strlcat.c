/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 16:29:58 by mlabouri          #+#    #+#             */
/*   Updated: 2019/11/14 13:13:29 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j2;
	size_t	j;
	char	c;

	i = 0;
	j = ft_strlen(dst);
	j2 = ft_strlen(src);
	if (j >= dstsize)
		return (dstsize + j2);
	while (src[i] != '\0')
	{
		c = (char)src[i];
		dst[j + i] = c;
		if (i == (dstsize - j - 1))
		{
			dst[dstsize - 1] = '\0';
			return (j + j2);
		}
		i++;
	}
	dst[j + i] = '\0';
	return (j + j2);
}
