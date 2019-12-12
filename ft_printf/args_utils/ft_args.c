/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_val_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 14:33:25 by mlabouri          #+#    #+#             */
/*   Updated: 2019/12/12 15:18:15 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trees.h"

char	ft_val_conv(const char *s, size_t i, unsigned long long int arg)
{
	char	(*func[5])(const char *, size_t, unsigned long long);
	char	convs[5];
	int		conv;

	func[0] = &val_int;
	func[1] = &val_char;
	func[2] = &val_string;
	func[3] = &val_pointer;
	convs[0] = 0;
	convs[1] = 'c';
	convs[2] = 's';
	convs[3] = 'p';
	conv = 1;
	while (s[i] != convs[conv] && convs[conv] != '\0')
		conv++;
	if (convs[conv] == '\0')
	{
		if (ft_cinset(s[i], INTS))
			return ((func)[0](s, i, arg));
		return (0);
	}
	return ((func)[conv](s, i, arg));
}

size_t	ft_args(const char *s, size_t i, unsigned long long int arg)
{
	char	args[4];
	char	bin[5];
	char	(*func[4])(const char *, size_t);
	char	flag;

	args[0] = '-';
	args[1] = '0';
	args[2] = '.';
	args[3] = '*';
	func[0] = &val_minus;
	func[1] = &val_zero;
	func[2] = &val_dot;
	func[3] = &val_42;
	flag = 0;
	while (ft_cinset(s[i], FLAGS))
	{
		while (s[i] != args[flag])
			flag++;
		bin[flag] = (func)[flag](s, i);
		i++;
	}
	bin[4] = ft_val_conv(s, i, arg);
	return (i + 1);
}
