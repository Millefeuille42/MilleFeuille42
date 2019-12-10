/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_val_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 14:33:25 by mlabouri          #+#    #+#             */
/*   Updated: 2019/12/10 13:32:08 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trees.h"

char			ft_val_flag(const char *s, size_t i)
{
	char	(*func[4])(const char *, size_t);
	char	flags[2][4];
	char	flag;

	func[0] = &val_minus;
	func[1] = &val_zero;
	func[2] = &val_dot;
	func[3] = &val_42;
	flags[0][0] = '-';
	flags[0][1] = '0';
	flags[0][2] = '.';
	flags[0][3] = '*';
	flag = 0;
	while (s[i] != flags[0][flag] || flags[0][flag] != '\0')
		flag++;
	if (flags[0][flag] == '\0')
		return (0);
	return ((func)[flag](s, i));
}

char			ft_val_conv(const char *s, size_t i, void **arg)
{
	char	(*func[5])(const char *, size_t, void **);
	char	flags[5];
	char	flag;

	func[0] = &val_int;
	func[1] = &val_char;
	func[2] = &val_string;
	func[3] = &val_pointer;
	func[4] = &val_percent;
	flags[1] = 'c';
	flags[2] = 's';
	flags[3] = 'p';
	flags[4] = '%';
	flag = 1;
	while (s[i] != flags[flag] || flags[flag] != '\0')
		flag++;
	if (flags[flag] == '\0')
	{
		if (ft_cinset(s[i], CONVS))
			return ((func)[0](s, i, arg));
		return (0);
	}
	return ((func)[flag](s, i, arg));
}
