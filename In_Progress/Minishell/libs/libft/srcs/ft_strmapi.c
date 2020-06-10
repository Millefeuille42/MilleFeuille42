/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:19:08 by dboyer            #+#    #+#             */
/*   Updated: 2020/05/08 17:31:06 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char			*result;
	size_t			len;
	unsigned int	i;

	if (s != NULL && (*f) != NULL)
	{
		i = 0;
		len = ft_strlen(s);
		if (!(result = (char *)malloc(len + sizeof(char))))
			return (NULL);
		while (s[i])
		{
			result[i] = (*f)(i, s[i]);
			i++;
		}
		result[i] = 0;
		return (result);
	}
	return (ft_strdup("\0"));
}
