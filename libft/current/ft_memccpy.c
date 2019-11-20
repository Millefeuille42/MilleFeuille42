/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 18:58:44 by dboyer            #+#    #+#             */
/*   Updated: 2019/11/15 17:31:30 by dboyer           ###   ########.fr       */
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
