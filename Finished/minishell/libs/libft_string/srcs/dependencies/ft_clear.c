/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 22:04:39 by mlabouri          #+#    #+#             */
/*   Updated: 2020/05/18 10:58:51 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft_string.h"

void				clear(char **pstr)
{
	int i;

	i = 0;
	if (pstr)
	{
		while (pstr[i])
		{
			free(pstr[i]);
			pstr[i] = NULL;
			i++;
		}
		free(pstr);
		pstr = NULL;
	}
}
