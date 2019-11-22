/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 15:01:31 by mlabouri          #+#    #+#             */
/*   Updated: 2019/11/22 15:01:31 by mlabouri         ###   ########.fr       */
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
