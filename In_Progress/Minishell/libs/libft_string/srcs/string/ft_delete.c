/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 10:58:51 by mlabouri          #+#    #+#             */
/*   Updated: 2020/05/18 10:58:51 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/string_object.h"

inline static char	*f_delete2(t_string *str, char *ret, const char *tmp)
{
	int i;
	int i2;

	i = 0;
	while (str->content + i != tmp)
	{
		ret[i] = str->content[i];
		i++;
	}
	i2 = 0;
	while (i2 < (int)str->size)
		i2++;
	i2 += i;
	while (str->content[i2])
	{
		ret[i] = str->content[i2];
		i++;
		i2++;
	}
	ret[i] = '\0';
	return (ret);
}

inline static char	f_delete(t_string *str, const char *str2)
{
	char *tmp;
	char *ret;

	if (!(tmp = ft_strnstr(str->content, str2, str->size + ft_strlen(str2))))
		return (1);
	if (!(ret = malloc(sizeof(char) * (str->size + 1 - ft_strlen(str2)))))
		return (2);
	str->size = ft_strlen(str2);
	ret = f_delete2(str, ret, tmp);
	str->clear(str);
	str->content = ret;
	str->size = ft_strlen(str->content);
	return (0);
}

void				ft_delete(t_string *str, const char *str2, int n)
{
	int i;

	i = 0;
	while (i != n && !f_delete(str, str2))
		i++;
}
