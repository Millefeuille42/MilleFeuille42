/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isflag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 10:44:41 by dboyer            #+#    #+#             */
/*   Updated: 2020/05/08 17:49:46 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline int		ft_isflag(const char *flag)
{
	int i;

	if (flag != NULL && flag[0] == '%')
	{
		i = 1;
		while (flag[i] && (ft_isdigit(flag[i]) || ft_cinset(flag[i], " -.*")))
			i++;
		return (ft_cinset(flag[i], CONVERTER));
	}
	return (0);
}
