/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 12:15:15 by mlabouri          #+#    #+#             */
/*   Updated: 2020/02/04 15:42:53 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*mem1;
	unsigned char	*mem2;

	if (s1 != NULL && s2 != NULL && s1 != s2 && n > 0)
	{
		i = 0;
		mem1 = (unsigned char *)s1;
		mem2 = (unsigned char *)s2;
		while (i < n)
		{
			if (mem1[i] != mem2[i])
				return (mem1[i] - mem2[i]);
			i++;
		}
	}
	return (0);
}
