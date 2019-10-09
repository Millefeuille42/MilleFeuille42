/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 16:11:08 by mlabouri          #+#    #+#             */
/*   Updated: 2019/10/09 16:44:43 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t 	i;
	char	*sub;

	i = 0;
	while (s[(size_t)start + i] != '\0' && i <= len)
		i++;
	sub = malloc(sizeof(char) * i)
	if (!sub)
		return (NULL);
	i = 0;
	while (s[(size_t)start + i] != '\0' && i <= len)
	{
		sub[i] = s[(size_t)start + i];
		i++;
	}
	return (sub);
}
