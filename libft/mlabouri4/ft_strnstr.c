/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 17:02:10 by mlabouri          #+#    #+#             */
/*   Updated: 2019/11/19 17:03:52 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_strnstr_2(const char *hay, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	i2;

	i = 0;
	while (i < len && hay[i])
	{
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

char			*ft_strnstr(const char *hay, const char *needle, size_t len)
{
	if (hay == NULL || hay[0] == '\0')
		return (NULL);
	if (needle == NULL || needle[0] == '\0' || hay == needle)
		return ((char *)hay);
	return (ft_strnstr_2(hay, needle, len));
}
