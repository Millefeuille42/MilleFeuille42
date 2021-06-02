/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 13:23:39 by mlabouri          #+#    #+#             */
/*   Updated: 2021/04/20 13:23:39 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

static t_bool	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

t_bool			ft_isnum(const char *str)
{
	while (str && *str)
	{
		if (!ft_isdigit(*str))
			return (false);
		str++;
	}
	return (true);
}

static t_bool	ft_cinset(const char c, const char *set)
{
	int	i;

	if (set != NULL)
	{
		i = 0;
		while (set[i])
		{
			if (c == set[i])
				return (true);
			i++;
		}
	}
	return (false);
}

static t_bool	ft_isspace(const char c)
{
	return (ft_cinset(c, "\t\n\r\v\f "));
}

int				ft_atoi(const char *str)
{
	int	i;
	int	result;

	result = 0;
	i = 0;
	if (str != NULL)
	{
		while (ft_isspace(*str))
			str++;
		if (*str == '-' || *str == '+')
			i = 1;
		while (str[i] && ft_isdigit(str[i]) != 0)
			result = result * 10 + (str[i++] - '0');
		if (*str == '-')
			return (-result);
		return (result);
	}
	return (0);
}
