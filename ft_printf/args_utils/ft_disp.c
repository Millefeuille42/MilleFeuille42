/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 16:09:27 by mlabouri          #+#    #+#             */
/*   Updated: 2020/01/30 11:30:22 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../trees/trees.h"

void ft_disp_convs(unsigned long long arg, char conv)
{
	static	void	(*func[255])(char, unsigned long long int);

	func['c'] = &disp_char;
	func['s'] = &disp_string;
	func['p'] = &disp_pointer;
	if (ft_cinset(conv, INTS))
		disp_int(conv, arg);
	else
		(func)[conv](conv, arg);
}

void ft_disp_flags(int bin[], unsigned long long arg, char conv)
{
	static	void	(*func2[255])(int [], unsigned long long int, char);
	size_t i;
	size_t i2;

	i2 = 0;
	func2['-'] = &disp_minus;
	func2['0'] = &disp_zero;
	func2['.'] = &disp_dot;
	func2['*'] = &disp_42;
	i = 0;
	while (i < 255)
	{
		if (bin[i])
		{
			func2[i](bin, arg, conv);
			i2++;
		}
		i++;
	}
	if (i2 == 0)
		ft_disp_convs(arg, conv);
}