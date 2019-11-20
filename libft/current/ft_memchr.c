/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:02:22 by dboyer            #+#    #+#             */
/*   Updated: 2019/11/15 16:07:14 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*mem;
	unsigned char	character;
	size_t			i;

	if (s != NULL)
	{
		i = 0;
		mem = (unsigned char*)s;
		character = (unsigned char)c;
		while (i < n)
		{
			if (mem[i] == character)
				return (&mem[i]);
			i++;
		}
	}
	return (NULL);
}
