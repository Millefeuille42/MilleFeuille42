/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 22:04:21 by mlabouri          #+#    #+#             */
/*   Updated: 2020/05/18 10:58:51 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft_string.h"

inline static char		*ft_copy(const char *src, char del)
{
	int		i;
	char	*dst;

	i = 0;
	if (!src || !src[0])
		return (0);
	while (src[i] && src[i] != del)
		i++;
	i++;
	if (!(dst = malloc(sizeof(char) * i)))
		return (NULL);
	i = 0;
	while (src[i] && src[i] != del)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}

size_t					count_lines(const char *str, char del)
{
	size_t	l;
	int		i;

	l = 1;
	i = 0;
	if (!str || !str[0])
		return (0);
	while (str[i])
	{
		if (str[i] == del)
			l++;
		i++;
	}
	return (l);
}

char					**ft_parse(char *str, char del)
{
	char	**ret;
	int		i;

	if (!(ret = malloc(sizeof(char *) * (count_lines(str, del) + 1))))
		return (NULL);
	i = 0;
	*ret = NULL;
	while (*str)
	{
		if (!(ret[i] = ft_copy(str, del)))
		{
			clear(ret);
			return (NULL);
		}
		while (*str && *str != del)
			str++;
		i++;
		if (*str)
			str++;
	}
	ret[i] = NULL;
	return (ret);
}
