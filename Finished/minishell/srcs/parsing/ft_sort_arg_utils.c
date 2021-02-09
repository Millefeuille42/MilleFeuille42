/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_arg_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 10:09:18 by mlabouri          #+#    #+#             */
/*   Updated: 2020/09/30 10:09:18 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_arg.h"

char	*ft_cdup(const char c)
{
	char	*ret;

	if (!(ret = ft_calloc(2, sizeof(char))))
		return (NULL);
	ret[0] = c;
	ret[1] = '\0';
	return (ret);
}

char	is_escape(const char *str, int i)
{
	char is;

	is = 0;
	if (i == 0)
		return (0);
	i--;
	while (i >= 0 && str[i] == '\\')
	{
		is = (char)!is;
		i--;
	}
	return (is);
}

int		skip_wp(char *input, int i)
{
	while (input[i] && ft_isspace(input[i]))
		i++;
	return (i);
}

int		skip_quote(const char *input, int i, char quote)
{
	i++;
	while (input[i] && !(input[i] == quote && !is_escape(input, i)))
		i++;
	if (input[i])
		i++;
	return (i);
}
