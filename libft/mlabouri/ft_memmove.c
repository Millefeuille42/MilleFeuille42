/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:30:14 by mlabouri          #+#    #+#             */
/*   Updated: 2019/10/14 11:52:42 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	temp[len];
	unsigned char	*mem1;
	unsigned char	*mem2;

	i = 0;
	mem1 = (unsigned char *)src;
	mem2 = (unsigned char *)dst;
	while (i < len)
	{
		temp[i] = mem1[i];
		i++;
	}
	i = 0;
	while (i < len)
	{
		mem2[i] = temp[i];
		i++;
	}
	return (mem2);
}