/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 16:20:34 by mlabouri          #+#    #+#             */
/*   Updated: 2019/11/04 18:56:18 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	i2;
	char	*join;

	i = 0;
	i2 = 0;
	if (!s1 && s2)
		return ((char *)s2)
	if (!s2 && s1)
		return ((char *)s1)
	if (!(join = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
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
	join[i + i2] = '\0';
	return (join);
}

#include <stdio.h>

int main(void)
{
	printf("%s\n", ft_strjoin(NULL, "TEST"));
	printf("%s\n", ft_strjoin("PING", NULL));
	printf("%s\n", ft_strjoin(NULL, NULL));
	return 0;
}

/*
if (!s1 || !s2)
	return ();
*/
