/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 17:13:43 by mlabouri          #+#    #+#             */
/*   Updated: 2019/12/23 12:16:56 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_check(char *str, int *check)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && (str[i] < '0' || str[i] > '9'))
	{
		if (*check != 0)
			return (NULL);
		if ((str[i] < 9 || str[i] > 13) && str[i] != ' ')
		{
			if (str[i] != '-' && str[i] != '+')
				return (NULL);
			else if (*check != 0)
				return (NULL);
		}
		if (str[i] == '-' && *check == 0)
			*check = 1;
		if (str[i] == '+' && *check == 0)
			*check = 2;
		i++;
	}
	return (str + i);
}

int			ft_atoi(const char *str)
{
	int	i;
	int	nb;
	int check;

	nb = 0;
	i = 0;
	check = 0;
	if (str == NULL)
		return (0);
	if (!(str = ft_check((char *)str, &check)))
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	if (check == 1)
		return (-nb);
	return (nb);
}
