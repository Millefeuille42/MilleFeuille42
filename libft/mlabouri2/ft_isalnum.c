/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 13:45:53 by mlabouri          #+#    #+#             */
/*   Updated: 2019/11/07 13:36:48 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (c < 65 || c > 90)
	{
		if (c < 97 || c > 122)
		{
			if (c < 48 || c > 57)
				return (0);
			return (3);
		}
		return (2);
	}
	return (1);
}
