/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:37:25 by dboyer            #+#    #+#             */
/*   Updated: 2019/11/15 17:18:41 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;

	if (count != 0 && size != 0)
	{
		if (!(mem = malloc(count * size)))
			return (NULL);
		ft_bzero(mem, count * size);
		return (mem);
	}
	return (malloc(1));
}
