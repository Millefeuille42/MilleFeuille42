/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_disp_tree.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 16:14:08 by mlabouri          #+#    #+#             */
/*   Updated: 2020/02/10 09:41:42 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/trees.h"

void	disp_minus(int bin[], unsigned long long int arg, char conv)
{
	int			length;
	static int	(*func[255])(char, unsigned long long int);

	if (bin['.'])
		return ;
	func['s'] = length_string;
	func['c'] = length_char;
	if (ft_cinset(conv, INTS))
		length = bin['-'] - length_int(conv, arg);
	else
		length = bin['-'] - func[(int)conv](conv, arg);
	ft_disp_convs(arg, conv);
	while (length > 0)
	{
		ft_putchar_fd(' ', 1);
		length--;
		g_count++;
	}
}

void	disp_zero(int bin[], unsigned long long int arg, char conv)
{
	int			length;
	static int	(*func[255])(char, unsigned long long int);

	if (bin['-'] || bin['.'])
		return ;
	func['s'] = length_string;
	func['c'] = length_char;
	if (ft_cinset(conv, INTS))
		length = bin['0'] - length_int(conv, arg);
	else
		length = bin['0'] - func[(int)conv](conv, arg);
	if (ft_cinset(conv, "di") && (int)arg < 0)
		arg = (unsigned long long)int_abs((int)arg);
	while (length > 0)
	{
		ft_putchar_fd('0', 1);
		length--;
		g_count++;
	}
	ft_disp_convs(arg, conv);
}

void	disp_dot(int bin[], unsigned long long int arg, char conv)
{
	int			length;

	if (bin['.'] < 0)
		bin['.'] = 0;
	if (ft_cinset(conv, INTS) && arg != 0)
	{
		length = bin['.'] - length_int(conv, arg);
		if (ft_cinset(conv, "di") && (int)arg < 0)
			arg = (unsigned long long)int_abs((int)arg);
		while (length > 0)
		{
			ft_putchar_fd('0', 1);
			length--;
			g_count++;
		}
		ft_disp_convs(arg, conv);
	}
	else if (conv == 's')
		ft_putnstr((char *)arg, bin['.']);
}

void	disp_pad(int bin[], unsigned long long int arg, char conv)
{
	int			length;
	static int	(*func[255])(char, unsigned long long int);

	func['s'] = length_string;
	func['c'] = length_char;
	if (ft_cinset(conv, INTS))
		length = bin[' '] - length_int(conv, arg);
	else
		length = bin[' '] - func[(int)conv](conv, arg);
	while (length > 0)
	{
		ft_putchar_fd(' ', 1);
		length--;
		g_count++;
	}
	ft_disp_convs(arg, conv);
}
