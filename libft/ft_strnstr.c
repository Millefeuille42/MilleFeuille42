/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 17:02:10 by mlabouri          #+#    #+#             */
/*   Updated: 2019/10/09 16:44:40 by mlabouri         ###   ########.fr       */
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
	while (1)
	{
		if (haystack[i] == '\0')
			return (NULL);
		if (i >= len)
			return (NULL);
		j = 0;
		i2 = i;
		while (haystack[i2] == needle[j])
		{
			i2++;
			j++;
			if (needle[j] == '\0')
				return (&haystack[i]);
		}
		i++;
	}
}
