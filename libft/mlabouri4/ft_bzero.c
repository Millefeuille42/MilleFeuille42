/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 11:40:11 by mlabouri          #+#    #+#             */
/*   Updated: 2019/11/19 12:07:47 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*mem;

	if (!s || n <= 0)
		return ;
	mem = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		mem[i] = 0;
		i++;
	}
}
