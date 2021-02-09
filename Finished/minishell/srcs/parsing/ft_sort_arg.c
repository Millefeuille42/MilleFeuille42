/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 18:07:45 by mlabouri          #+#    #+#             */
/*   Updated: 2020/10/21 17:38:26 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_arg.h"

static	int		get_next_arg(char **temp, char *str, int *i)
{
	int		i2;
	int		in_i;
	char	flag;

	i2 = *i;
	in_i = (int)*i;
	flag = 1;
	*temp = NULL;
	while (str[in_i] && !(ft_isspace((str)[in_i])
				&& !is_escape((str), in_i) && !(flag = 0)))
		if ((!is_escape(str, in_i) && (str[in_i] == '"' || str[in_i] == '\''))
				|| !(in_i = in_i + 1))
			in_i = skip_quote(str, in_i, str[in_i]);
	if (!str[i2])
		return (0);
	if (!(*temp = ft_substr(str, i2, in_i - i2)))
		return (-1);
	*i = skip_wp(str, in_i);
	return (!flag);
}

char			**ft_sort_arg(char *str)
{
	int		i;
	int		len;
	char	*temp;
	char	**ret;

	len = 0;
	i = 0;
	while (get_next_arg(&temp, str, &i) && (len += 1))
		safe_free((void **)&temp);
	if (temp)
		safe_free((void **)&temp);
	if (!(ret = calloc(sizeof(char *), len + 2)))
		return (NULL);
	ret[len + 1] = NULL;
	i = 0;
	len = 0;
	while (get_next_arg(&ret[len], str, &i) && ret[len])
		len++;
	ret = clean_args(ret);
	return (ret);
}
