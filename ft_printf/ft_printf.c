/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 12:31:46 by mlabouri          #+#    #+#             */
/*   Updated: 2020/02/12 15:30:25 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/trees.h"

int			g_count;
int			(*g_func_length[255])(char, unsigned long long int);
void		(*g_func_conv[255])(unsigned long long int);

static void		init(void)
{
	g_func_length['s'] = length_string;
	g_func_length['c'] = length_char;
	g_func_length['p'] = length_pointer;
	g_func_conv['c'] = &disp_char;
	g_func_conv['s'] = &disp_string;
	g_func_conv['p'] = &disp_pointer;
}

int				ft_printf(const char *input, ...)
{
	va_list				args;
	size_t				i;
	static	size_t		len;

	init();
	va_start(args, input);
	i = 0;
	g_count = 0;
	len = ft_strlen(input);
	while (i < len)
	{
		i = ft_putstr_fd_c((char *)input, 1, '%', i);
		if (input[i] == '\0')
			return (g_count);
		i = ft_args((char *)input, i + 1, &args);
	}
	return (g_count);
}

/*
 * . || c, rien
 * . || s, max de char
 * . || si . == 0 et i == 0 ou s, afficher rien

 * Width < 0 == - Padding
 * - == 0 padding null
 * 0 padding = width si .
*/