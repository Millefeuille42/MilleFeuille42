/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_disp_tree.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 16:14:08 by mlabouri          #+#    #+#             */
/*   Updated: 2020/01/30 11:44:10 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trees.h"

void	disp_minus(int bin[], unsigned long long int arg, char conv)
{
	int 		length;
	static	int	(*func[255])(char, unsigned long long int);

	func['s'] = length_string;
	func['c'] = length_char;
	if (ft_cinset(conv, INTS))
		length = bin['-'] - length_int(conv, arg);
	else
		length = bin['-'] - func[conv](conv, arg);
	ft_disp_convs(arg, conv);
	while (length != 0)
	{
		ft_putchar_fd(' ', 1);
		length--;
	}
}

void	disp_zero(int bin[], unsigned long long int arg, char conv)
{
	int 		length;
	static	int	(*func[255])(char, unsigned long long int);

	if (bin['-'])
		return;
	func['s'] = length_string;
	func['c'] = length_char;
	if (ft_cinset(conv, INTS))
		length = bin['0'] - length_int(conv, arg);
	else
		length = bin['0'] - func[conv](conv, arg);
	while (length != 0)
	{
		ft_putchar_fd('0', 1);
		length--;
	}
	ft_disp_convs(arg, conv);
}

void	disp_dot(int bin[], unsigned long long int arg, char conv)
{

}

void	disp_42(int bin[], unsigned long long int arg, char conv)
{

}