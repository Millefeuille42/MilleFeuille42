/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 16:14:27 by mlabouri          #+#    #+#             */
/*   Updated: 2020/02/12 17:14:34 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/trees.h"

size_t	ft_args(char *s, size_t i, va_list *args)
{
	struct s_f	bin;

	bin = ft_szero(bin);
	while (ft_cinset(s[i], FLAGS) || ft_isdigit0(s[i]))
	{
		if ((ft_isdigit0(s[i]) || s[i] == '*') && !(bin.zero) && !(bin.minus))
			bin.pad = val_pad(s, i, args);
		if (s[i] == '.')
			bin.dot = val_dot(s, i + 1, args, &(bin.dotc));
		if (s[i] == '-' && !bin.dotc)
			bin.minus = val_minus(s, i + 1, args);
		if (s[i] == '0' && !bin.dotc)
			bin.zero = val_zero(s, i + 1, args, &(bin.zeros));
		i++;
		while (ft_isdigit(s[i]) || s[i] == '*')
			i++;
	}
	if (s[i] == '%')
		ft_disp_flags(bin, (unsigned long long int)'%', 'c');
	else if (!(ft_cinset(s[i], ALL)))
		return (i);
	else
		ft_disp_flags(bin, va_arg(*args, unsigned long long), s[i]);
	return (i + 1);
}