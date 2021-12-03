/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:33:43 by mlabouri          #+#    #+#             */
/*   Updated: 2021/12/03 13:33:43 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Millefeuille on 22/06/2021.
//

#include "../so_long.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (s1 != NULL && s2 != NULL && n != 0)
	{
		while ((*s1 || *s2) && *s1 == *s2 && --n > 0)
		{
			s1++;
			s2++;
		}
		return (((unsigned char)*s1 - (unsigned char)*s2));
	}
	return (0);
}
