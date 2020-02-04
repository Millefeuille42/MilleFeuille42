/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 17:02:10 by mlabouri          #+#    #+#             */
/*   Updated: 2020/02/04 15:42:53 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *haystack, char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	i2;

	i = 0;
	if (needle[0] == '\0')
		return (haystack);
	while (i < len)
	{
		if (haystack[i] == '\0')
			return (NULL);
		j = 0;
		i2 = i;
		while (haystack[i2] == needle[j])
		{
			i2++;
			j++;
			if (i2 >= len)
				return (NULL);
			if (needle[j] == '\0')
				return (&haystack[i]);
		}
		i++;
	}
	return (NULL);
}
