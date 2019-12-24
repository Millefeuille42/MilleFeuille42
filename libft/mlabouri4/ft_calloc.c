/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 13:01:27 by mlabouri          #+#    #+#             */
/*   Updated: 2019/12/23 12:16:56 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t			i;
	unsigned char	*memzone;
	size_t			total;

	if (count <= 0 || size <= 0)
		total = 1;
	total = count * size;
	memzone = malloc(total);
	if (!memzone)
		return (NULL);
	i = 0;
	while (i < total)
	{
		memzone[i] = 0;
		i++;
	}
	return ((void *)memzone);
}
