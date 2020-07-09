/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 10:58:51 by mlabouri          #+#    #+#             */
/*   Updated: 2020/06/23 17:00:29 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/string_object.h"

 static size_t	diff(const char *str1, const char *str2)
{
	return (ft_strlen(str1) - ft_strlen(str2));
}

 static void		ft_prog(int *i, char *ret, const char *tmp,
		const char *str)
{
	*i = 0;
	while (str + *i != tmp)
	{
		ret[*i] = str[*i];
		*i = *i + 1;
	}
}

 static char		*copy(t_string *str, char *ret, const char *tmp,
		const char *new)
{
	int i;
	int i2;
	int i3;

	ft_prog(&i, ret, tmp, str->content);
	i2 = 0;
	while (new[i2])
	{
		ret[i + i2] = new[i2];
		i2++;
	}
	str->size += i;
	i3 = i;
	while (i3 < (int)str->size)
		i3++;
	while (str->content[i3])
	{
		ret[i + i2] = str->content[i3];
		i3++;
		i++;
	}
	ret[i + i2] = '\0';
	return (ret);
}

 static char		replace(t_string *str, const char *old, const char *new)
{
	char *tmp;
	char *ret;

	if (!(tmp = ft_strnstr(str->content, old, str->size + ft_strlen(old))))
		return (1);
	if (!(ret = malloc(sizeof(char) * (str->size + 1 + (diff(new, old))))))
		return (2);
	str->size = ft_strlen(old);
	ret = copy(str, ret, tmp, new);
	str->clear(str);
	str->content = ret;
	str->size = ft_strlen(str->content);
	return (0);
}

void					ft_replace(t_string *str, const char *old,
		const char *new, int n)
{
	int i;

	i = 0;
	while (i != n && !replace(str, old, new))
		i++;
}
