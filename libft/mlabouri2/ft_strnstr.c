/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 17:02:10 by mlabouri          #+#    #+#             */
/*   Updated: 2019/11/04 18:44:40 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	i2;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)hay);
	while (i < len)
	{
		if (hay[i] == '\0')
			return (NULL);
		j = 0;
		i2 = i;
		while (hay[i2] == needle[j])
		{
			i2++;
			j++;
			if (i2 >= len)
				return (NULL);
			if (needle[j] == '\0')
				return ((char *)&hay[i]);
		}
		i++;
	}
	return (NULL);
}
