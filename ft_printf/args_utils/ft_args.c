/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 16:14:27 by mlabouri          #+#    #+#             */
/*   Updated: 2020/01/30 11:34:54 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../trees/trees.h"

size_t			ft_args(char *s, size_t i, va_list *args)
{
	int			bin[255];
	static	int	(*func[255])(const char *, size_t);

	func['-'] = &val_minus;
	func['0'] = &val_zero;
	func['.'] = &val_dot;
	func['*'] = &val_42;
	ft_szero(bin, 255);
	while (ft_cinset(s[i], FLAGS))
	{
		bin[s[i]] = (func)[s[i]](s, (i + 1));
		if (ft_cinset(s[i++], "0-"))
			while (ft_isdigit(s[i]))
				i++;
		else
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