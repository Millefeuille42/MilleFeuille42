/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:11:26 by dboyer            #+#    #+#             */
/*   Updated: 2019/11/15 16:02:21 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*buffer;
	size_t			i;

	if (b != NULL)
	{
		i = 0;
		buffer = (unsigned char *)b;
		while (i < len)
		{
			buffer[i] = (unsigned char)c;
			i++;
		}
	}
	return (b);
}
