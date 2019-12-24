/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 14:39:35 by mlabouri          #+#    #+#             */
/*   Updated: 2019/12/23 12:16:56 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_trimlen(char const *s1, char const *set, size_t len)
{
	size_t	i;
	size_t	i2;

	i = 0;
	while (s1[i] != '\0')
	{
		i2 = 0;
		while (set[i2] != '\0' && s1[i] != set[i2])
			i2++;
		if (set[i2] == '\0')
			break ;
		if (s1[i] == set[i2])
			len++;
		i++;
	}
	return (len);
}

static size_t	ft_rtrimlen(char const *s1, char const *set, size_t len)
{
	size_t	i;
	size_t	i2;

	i = 0;
	while (s1[i] != '\0')
		i++;
	i--;
	while (i != 0)
	{
		i2 = 0;
		while (set[i2] != '\0' && s1[i] != set[i2])
			i2++;
		if (set[i2] == '\0')
			break ;
		if (s1[i] == set[i2])
			len++;
		i--;
	}
	return (len);
}

static	char	*ft_trim(char const *s1, char const *set, char *trim)
{
	size_t	start;
	size_t	end;
	size_t	i;

	start = ft_trimlen(s1, set, 0);
	i = 0;
	while (s1[i] != '\0')
		i++;
	end = i - ft_rtrimlen(s1, set, 0);
	i = 0;
	while (i + start < end)
	{
		trim[i] = s1[i + start];
		i++;
	}
	trim[i] = '\0';
	return (trim);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	i;
	char	*trim;

	i = 0;
	len = ft_trimlen(s1, set, 0);
	len = ft_rtrimlen(s1, set, len);
	while (s1[i] != '\0')
		i++;
	if ((len + 1) > i)
		return ("\0");
	trim = malloc(sizeof(char) * (i - len + 1));
	if (!trim)
		return (NULL);
	trim = ft_trim(s1, set, trim);
	return (trim);
}
