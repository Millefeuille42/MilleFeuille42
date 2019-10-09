/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 17:13:43 by mlabouri          #+#    #+#             */
/*   Updated: 2019/10/08 17:22:30 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	nb;
	int check;

	check = 0;
	nb = 0;
	i = 0;
	while (str[i] != '\0' && (str[i] < '0' || str[i] > '9'))
	{
		if (check != 0)
			return (nb);
		if (str[i] == '-' && check == 0)
			check = 1;
		if ((str[i] < 9 || str[i] > 13) && str[i] != ' ' && str[i] != '-')
			return (nb);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	if (check != 0)
		return (-nb);
	return (nb);
}
