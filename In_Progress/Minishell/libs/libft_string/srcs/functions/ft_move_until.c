/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_until.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 11:15:18 by dboyer            #+#    #+#             */
/*   Updated: 2020/05/18 10:58:51 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft_string.h"

char	*ft_move_until(char *str, char *bool, int (*f)(int))
{
	if (str)
	{
		if (ft_str_isequal(bool, "is"))
		{
			while (*str && !f(*str))
				str++;
			return (f(*str) && *str ? str : NULL);
		}
		else if (ft_str_isequal(bool, "not"))
		{
			while (*str && f(*str))
				str++;
			return (!f(*str) && *str ? str : NULL);
		}
	}
	return (str);
}
