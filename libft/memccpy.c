/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memccpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:26:10 by mlabouri          #+#    #+#             */
/*   Updated: 2019/10/08 15:08:15 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*mem1;
	unsigned char	*mem2;

	i = 0;
	mem1 = (unsigned char *)src;
	mem2 = (unsigned char *)dst;
	while (i < n)
	{
		mem2[i] = mem1[i];
		if (mem1[i] == (unsigned char)c)
			return (mem2 + i + 1);
		i++;
	}
	return (NULL);
}
