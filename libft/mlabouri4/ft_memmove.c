/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:30:14 by mlabouri          #+#    #+#             */
/*   Updated: 2020/02/04 15:42:53 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*mem1;
	unsigned char	*mem2;

	i = 0;
	if (dst == NULL || src == NULL)
		return (NULL);
	mem1 = (unsigned char *)src;
	mem2 = (unsigned char *)dst;
	if (len == 0)
		return (mem2);
	if (mem1 < mem2)
	{
		while (len > 0)
		{
			mem2[len - 1] = mem1[len - 1];
			len--;
		}
	}
	else if (mem1 > mem2)
		ft_memcpy(mem2, mem1, len);
	return (mem2);
}
