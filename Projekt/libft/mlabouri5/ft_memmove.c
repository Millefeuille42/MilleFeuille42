/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 15:01:25 by mlabouri          #+#    #+#             */
/*   Updated: 2019/11/22 15:01:25 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *d;
	unsigned char *s;

	if (dst != NULL && src != NULL && src != dst)
	{
		if (src <= dst)
		{
			d = (unsigned char *)dst;
			s = (unsigned char *)src;
			while (len--)
				d[len] = s[len];
		}
		else
			ft_memcpy(dst, src, len);
		return (dst);
	}
	return (NULL);
}
