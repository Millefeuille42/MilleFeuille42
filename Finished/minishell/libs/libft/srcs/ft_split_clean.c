/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_clean.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 19:27:46 by dboyer            #+#    #+#             */
/*   Updated: 2020/05/08 17:36:03 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_split_clean(char ***split)
{
	int		i;
	char	**cpy;

	i = 0;
	cpy = *split;
	if (!cpy)
		return ;
	while (cpy[i])
	{
		free(cpy[i]);
		cpy[i] = NULL;
		i++;
	}
	free(*split);
	*split = NULL;
}
