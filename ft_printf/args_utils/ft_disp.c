/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 16:09:27 by mlabouri          #+#    #+#             */
/*   Updated: 2019/12/20 14:15:35 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../trees/trees.h"

void ft_disp(char bin[], unsigned long long arg, char conv)
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