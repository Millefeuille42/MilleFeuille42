/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 16:21:41 by mlabouri          #+#    #+#             */
/*   Updated: 2019/11/20 16:00:58 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t j;

	j = 0;
	if (src == NULL || dst == NULL)
		return (0);
	while (src[j] != '\0')
		j++;
	if (!dst)
		return (j);
	i = 0;
	while (src[i] != '\0' && i < dstsize)
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize > 0)
	{
		if (j == 0 || j < dstsize)
			dst[i] = '\0';
		else
			dst[i - 1] = '\0';
	}
	return (j);
}
