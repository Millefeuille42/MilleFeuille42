/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 11:05:55 by mlabouri          #+#    #+#             */
/*   Updated: 2020/02/04 15:42:53 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	c1;
	unsigned char	c2;
	size_t			i;

	i = 0;
	if (n <= 0)
		return (0);
	while (1)
	{
		c1 = (unsigned char)s1[i];
		c2 = (unsigned char)s2[i];
		if (i > n - 1)
			return (0);
		if (c1 != c2)
			return (c1 - c2);
		if (c1 == '\0' || c2 == '\0')
			return (c1 - c2);
		i++;
	}
	return (c1 - c2);
}
