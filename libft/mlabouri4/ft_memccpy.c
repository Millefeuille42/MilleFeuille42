/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:26:10 by mlabouri          #+#    #+#             */
/*   Updated: 2019/11/15 18:35:24 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	char			*mem1;
	char			*mem2;

	i = 0;
	if (!dst && !src)
		return (NULL);
	mem1 = (char *)src;
	mem2 = (char *)dst;
	while (i < n)
	{
		mem2[i] = mem1[i];
		if (mem1[i] == (char)c)
			return ((void *)(mem2 + i + 1));
		i++;
	}
	return (NULL);
}
