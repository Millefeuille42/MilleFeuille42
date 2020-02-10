/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_val_tree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 16:13:55 by mlabouri          #+#    #+#             */
/*   Updated: 2020/02/10 09:43:00 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/trees.h"

int	val_minus(const char *s, size_t i, va_list *args)
{
	int		start;
	int		end;

	start = 0;
	end = 0;
	while (ft_isdigit(s[i]))
	{
		if (start == 0)
			start = i;
		else
			end = i;
		i++;
	}
	if (s[i] == '*' && !(ft_isdigit(s[i + 1])))
		return (va_arg(*args, int));
	if (s[i] == '*' && ft_isdigit(s[i + 1]))
	{
		end = va_arg(*args, int);
		return (val_minus(s, i + 1, args));
	}
	if (start == 0)
		return (0);
	if (end == 0)
		return (s[start] - 48);
	return (atoi_mk2(s, start, end));
}

int	val_zero(const char *s, size_t i, va_list *args)
{
	int		start;
	int		end;

	start = 0;
	end = 0;
	while (ft_isdigit(s[i]))
	{
		if (start == 0)
			start = i;
		else
			end = i;
		i++;
	}
	if (s[i] == '*' && !(ft_isdigit(s[i + 1])))
		return (va_arg(*args, int));
	if (s[i] == '*' && ft_isdigit(s[i + 1]))
	{
		end = va_arg(*args, int);
		return (val_zero(s, i + 1, args));
	}
	if (start == 0)
		return (0);
	if (end == 0)
		return (s[start] - 48);
	return (atoi_mk2(s, start, end));
}

int	val_dot(const char *s, size_t i, va_list *args)
{
	int		start;
	int		end;

	start = 0;
	end = 0;
	while (ft_isdigit(s[i]))
	{
		if (start == 0)
			start = i;
		else
			end = i;
		i++;
	}
	if (s[i] == '*' && !(ft_isdigit(s[i + 1])))
		return (va_arg(*args, int));
	if (s[i] == '*' && ft_isdigit(s[i + 1]))
	{
		end = va_arg(*args, int);
		return (val_dot(s, i + 1, args));
	}
	if (start == 0)
		return (-1);
	if (end == 0)
		return (s[start] - 48);
	return (atoi_mk2(s, start, end));
}

int	val_pad(const char *s, size_t i, va_list *args)
{
	int	start;
	int	end;

	start = 0;
	end = 0;
	while (ft_isdigit(s[i]))
	{
		if (start == 0)
			start = i;
		else
			end = i;
		i++;
	}
	if (s[i] == '*' && !(ft_isdigit(s[i + 1])))
		return (va_arg(*args, int));
	if (s[i] == '*' && ft_isdigit(s[i + 1]))
	{
		end = va_arg(*args, int);
		return (val_pad(s, i + 1, args));
	}
	if (start == 0)
		return (0);
	if (end == 0)
		return (s[start] - 48);
	return (atoi_mk2(s, start, end));
}
