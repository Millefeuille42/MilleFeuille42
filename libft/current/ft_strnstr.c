/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:21:42 by dboyer            #+#    #+#             */
/*   Updated: 2019/11/15 17:00:14 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t n;

	if (haystack != NULL && needle != NULL && *needle)
	{
		n = ft_strlen(needle);
		while (*haystack && len-- >= n)
		{
			if (ft_strncmp(haystack, needle, n) == 0)
				return ((char *)haystack);
			haystack++;
		}
		return (NULL);
	}
	return ((char *)haystack);
}
