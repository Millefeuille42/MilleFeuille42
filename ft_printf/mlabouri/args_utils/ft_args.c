/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 16:14:27 by mlabouri          #+#    #+#             */
/*   Updated: 2019/12/20 17:13:05 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../trees/trees.h"

size_t	ft_args(char *s, size_t i, unsigned long long int arg)
{
	char			bin[255];
	static	char	(*func[255])(const char *, size_t);

	func['-'] = &val_minus;
	func['0'] = &val_zero;
	func['.'] = &val_dot;
	func['*'] = &val_42;
	while (ft_cinset(s[i], FLAGS))
	{
		bin[s[i]] = (func)[s[i]](s, i);
		i++;
	}
	if (s[i] == '%')
		ft_disp(bin, (unsigned long long int)'%', 'c');
	else if (!(ft_cinset(s[i], ALL)))
		return (i);
	else
		ft_disp(bin, arg, s[i]);
	return (i + 1);
}