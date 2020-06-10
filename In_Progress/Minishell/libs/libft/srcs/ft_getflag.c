/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getflag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 11:15:15 by dboyer            #+#    #+#             */
/*   Updated: 2020/05/08 17:49:33 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline char	*ft_getflag(const char *occurence)
{
	int i;

	if (occurence != NULL && ft_isflag(occurence))
	{
		i = 1;
		while (occurence[i])
		{
			if (ft_cinset(occurence[i], CONVERTER))
				return (ft_substr(occurence, 0, i + 1));
			i++;
		}
	}
	return (NULL);
}
