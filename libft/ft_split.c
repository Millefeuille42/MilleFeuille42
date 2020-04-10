/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 14:06:41 by mlabouri          #+#    #+#             */
/*   Updated: 2020/04/10 14:06:41 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	**ft_null_string(void)
{
	char **stringset;

	if (!(stringset = malloc(sizeof(char *))))
		return (NULL);
	if (!(stringset[0] = malloc(sizeof(char))))
		return (NULL);
	stringset[0][0] = '\0';
	return (stringset);
}

static	char	**ft_makestringset(char const *s, char c)
{
	size_t	i;
	size_t	size;
	char	**stringset;
	char	check;

	i = 0;
	size = 1;
	check = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0' && check != 0)
			size++;
		if (s[i] != c && check != 1)
			check = 1;
		i++;
	}
	i = 0;
	while (s[i] == c)
		i++;
	if (s[i] == '\0')
		size = 0;
	if (!(stringset = malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	return (stringset);
}

static	char	*ft_makestring(char const *s, char c)
{
	size_t	i;
	char	*string;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	if (!(string = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	return (string);
}

static	char	*ft_writestring(char const *s, char c, char *string, size_t *i)
{
	size_t	i2;

	i2 = 0;
	while (s[*i] != '\0' && s[*i] != c)
	{
		string[i2] = s[*i];
		*i = *i + 1;
		i2++;
	}
	string[i2] = '\0';
	if (s[*i] != '\0')
		*i = *i + 1;
	return (string);
}

char			**ft_split(char const *s, char c)
{
	char	**set;
	size_t	i;
	size_t	set_i;

	if (!s)
		return (ft_null_string());
	i = 0;
	set_i = 0;
	if (!(set = ft_makestringset(s, c)))
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			if (!(set[set_i] = ft_makestring(s + i, c)))
				return (NULL);
			set[set_i] = ft_writestring(s, c, set[set_i], &i);
			set_i++;
		}
		else
			i++;
	}
	set[set_i] = NULL;
	return (set);
}
