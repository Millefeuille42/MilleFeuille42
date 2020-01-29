/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:28:02 by mlabouri          #+#    #+#             */
/*   Updated: 2019/11/14 15:11:44 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*mem;

	i = 0;
	if (!s)
		return (NULL);
	mem = (unsigned char *)s;
	while (i < n)
	{
		if (mem[i] == (unsigned char)c)
			return ((void *)mem + i);
		i++;
	}
	return (NULL);
}
