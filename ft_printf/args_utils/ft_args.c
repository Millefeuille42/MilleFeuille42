/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 16:14:27 by mlabouri          #+#    #+#             */
/*   Updated: 2020/02/10 10:06:12 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/trees.h"

size_t	ft_args(char *s, size_t i, va_list *args)
{
	int			bin[255];
	static int	(*func[255])(const char *, size_t, va_list *);

	func['-'] = &val_minus;
	func['0'] = &val_zero;
	func['.'] = &val_dot;
	ft_szero(bin, 255);
	while (ft_cinset(s[i], FLAGS) || ft_isdigit0(s[i]))
	{
		if ((ft_isdigit0(s[i]) || s[i] == '*') && !(bin['0']) && !(bin['-']))
			bin[' '] = val_pad(s, i, args);
		else
			bin[(int)s[i]] = (func)[(int)s[i]](s, (i + 1), args);
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
