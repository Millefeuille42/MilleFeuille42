/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 14:06:41 by mlabouri          #+#    #+#             */
/*   Updated: 2020/05/07 12:19:21 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/trees.h"

static void	ft_detarg(struct s_c arg, char co, va_list *args, struct s_f bin)
{
	if (co == 'c')
		arg.ch = (char)va_arg(*args, int);
	else if (co == 's')
	{
		arg.s = va_arg(*args, char *);
		if (arg.s == NULL)
			arg.s = "(null)";
	}
	else if (co == 'p')
		arg.p = va_arg(*args, long);
	else if (ft_cinset(co, INTS))
		arg.diux = va_arg(*args, unsigned);
	else
	{
		arg.ch = '%';
		co = 'c';
	}
	ft_disp_flags(bin, arg, co);
}

size_t		ft_args(char *s, size_t i, va_list *args)
{
	struct s_f	bin;
	struct s_c	arg;

	ft_szero(&bin, &arg);
	while (ft_cinset(s[i], FLAGS) || ft_isdigit0(s[i]))
	{
		if ((ft_isdigit0(s[i]) || s[i] == '*') && !(bin.zero) && !(bin.minus))
			bin.pad = val_pad(s, i, args);
		if (s[i] == '.')
			bin.dot = val_dot(s, i + 1, args, &(bin.dotc));
		if (s[i] == '-' && !bin.dotc)
			bin.minus = val_minus(s, i + 1, args);
		if (s[i] == '0' && !bin.dotc)
			bin.zero = val_zero(s, i + 1, args);
		i++;
		while (ft_isdigit(s[i]) || s[i] == '*')
			i++;
	}
	if (!(ft_cinset(s[i], ALL)))
		return (i);
	ft_detarg(arg, s[i], args, bin);
	return (i + 1);
}
