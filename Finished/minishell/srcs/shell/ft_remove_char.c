/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 09:35:13 by dboyer            #+#    #+#             */
/*   Updated: 2020/06/18 09:40:28 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_remove_char(char *input, char c)
{
	char	**splitted;
	char	*result;
	char	*tmp;
	int		i;

	i = 0;
	result = NULL;
	splitted = ft_split(input, c);
	while (splitted[i])
	{
		printf("I = %d\n", i);
		if (result)
		{
			tmp = ft_strjoin(result, splitted[i]);
			safe_free((void **)&result);
			result = tmp;
		}
		else
			result = ft_strdup(splitted[i]);
		i++;
	}
	ft_split_clean(&splitted);
	return (result);
}
