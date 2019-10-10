/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 16:20:34 by mlabouri          #+#    #+#             */
/*   Updated: 2019/10/10 15:55:09 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	i2;
	char	*join;

	i = 0;
	i2 = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[i2] != '\0')
		i2++;
	join = malloc(sizeof(char) * (i + i2));
	if (!join)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		join[i] = s1[i];
		i++;
	}
	while (s2[i2] != '\0')
	{
		join[i + i2] = s2[i2];
		i2++;
	}
	return (join);
}
