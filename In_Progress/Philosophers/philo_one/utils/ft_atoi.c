/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 14:06:41 by mlabouri          #+#    #+#             */
/*   Updated: 2020/05/07 12:19:22 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_one.h"

static	int		ft_cinset(const char c, const char *set)
{
	int i;

	if (set != NULL)
	{
		i = 0;
		while (set[i])
		{
			if (c == set[i])
				return (1);
			i++;
		}
		return (0);
	}
	return (-1);
}

static	int		ft_isspace(const char c)
{
	return (ft_cinset(c, "\t\n\r\v\f "));
}

static	int		ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int				ft_atoi(const char *str)
{
	int	i;
	int	result;

	if (str != NULL)
	{
		result = 0;
		while (ft_isspace(*str))
			str++;
		i = str[0] == '-' || str[0] == '+' ? 1 : 0;
		while (str[i] && ft_isdigit(str[i]) != 0)
			result = result * 10 + (str[i++] - '0');
		return (str[0] == '-') ? result * -1 : result;
	}
	return (0);
}

