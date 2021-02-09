/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 15:09:00 by dboyer            #+#    #+#             */
/*   Updated: 2020/06/16 16:23:42 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_extract_env(char *str)
{
	char	**result;
	int		i;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	if (str[i])
	{
		if (!(result = (char **)ft_calloc(sizeof(char *), 3)))
			return (NULL);
		result[0] = ft_substr(str, 0, i);
		result[1] = ft_strdup(&str[i + 1]);
		result[2] = NULL;
		return (result);
	}
	return (NULL);
}
