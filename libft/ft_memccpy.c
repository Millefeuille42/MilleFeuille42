/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 14:06:41 by mlabouri          #+#    #+#             */
/*   Updated: 2020/04/30 18:34:45 by millefeui        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;
	size_t			i;

	if (dst != NULL && src != NULL && src != dst)
	{
		i = 0;
		s = (unsigned char *)src;
		d = (unsigned char *)dst;
		while (i < n)
		{
			d[i] = s[i];
			if (s[i] == (unsigned char)c)
				return (d + i + 1);
			i++;
		}
	}
	return (NULL);
}
