/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:05:25 by dboyer            #+#    #+#             */
/*   Updated: 2020/05/08 17:50:25 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*first;
	unsigned char	*second;

	if (s1 != NULL && s2 != NULL && s1 != s2 && n != 0)
	{
		first = (unsigned char *)s1;
		second = (unsigned char *)s2;
		while (*first == *second && --n > 0)
		{
			first++;
			second++;
		}
		return ((int)(*first - *second));
	}
	return (0);
}
