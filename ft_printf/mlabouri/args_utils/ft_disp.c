/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 16:09:27 by mlabouri          #+#    #+#             */
/*   Updated: 2019/12/24 11:24:41 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../trees/trees.h"

void ft_disp(char bin[], unsigned long long arg, char conv)
{
	static	void	(*func[255])(char, unsigned long long int);
	size_t i;

	func['c'] = &disp_char;
	func['s'] = &disp_string;
	func['p'] = &disp_pointer;
	i = 0;
	while (bin[i]  != '0')
	{
		if (bin[i] == 1)
			func[i](conv, arg);
		i++;
	}
	if (ft_cinset(conv, INTS))
		disp_int(conv, arg);
	else
		(func)[conv](conv, arg);
}