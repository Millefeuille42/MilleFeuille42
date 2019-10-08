/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 11:01:40 by mlabouri          #+#    #+#             */
/*   Updated: 2019/10/08 17:36:37 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*mem;

	i = 0;
	mem = (unsigned char *)b;
	while (i < len)
	{
		mem[i] = (unsigned char)c;
		i++;
	}
	return (mem);
}
