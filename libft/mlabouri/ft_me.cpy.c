/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 11:51:37 by mlabouri          #+#    #+#             */
/*   Updated: 2020/02/04 15:42:53 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
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
		i++;
	}
	return (mem2);
}
