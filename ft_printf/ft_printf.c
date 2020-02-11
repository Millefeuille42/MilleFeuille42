/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 12:31:46 by mlabouri          #+#    #+#             */
/*   Updated: 2020/02/10 12:21:56 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/trees.h"
#include <stdio.h>

int			g_count;
int			(*g_func_length[255])(char, unsigned long long int);
void		(*g_func_conv[255])(unsigned long long int);
int			(*g_func_fval[255])(const char *, size_t, va_list *);
void		(*g_func_fdisp[255])(int[], unsigned long long int, char);

static void		init(void)
{
	g_func_length['s'] = length_string;
	g_func_length['c'] = length_char;
	g_func_length['p'] = length_pointer;
	g_func_conv['c'] = &disp_char;
	g_func_conv['s'] = &disp_string;
	g_func_conv['p'] = &disp_pointer;
	g_func_fval['-'] = &val_minus;
	g_func_fval['0'] = &val_zero;
	g_func_fval['.'] = &val_dot;
	g_func_fdisp['-'] = &disp_minus;
	g_func_fdisp['0'] = &disp_zero;
	g_func_fdisp['.'] = &disp_dot;
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

int main(void)
{
	int rep;
	int rep2;

	rep = ft_printf("\n%2i, %2d, %2d, %2d, %2d, %2d, %2d, %2d", 8, -12, 123456789,  0, -12345678, 97, -2147483648, 2147483647);
	rep2 = printf("\n%2i, %2d, %2d, %2d, %2d, %2d, %2d, %2dhh", 8, -12, 123456789,  0, -12345678, 97, -2147483648, 2147483647);

	printf("\n%d :: %d", rep, rep2);
}

/*
**		0 : s, c, p		||	undefined behavior
**		* : *, digit	||	undefined behavior
**		. : -, p, c		||	undefined behavior
*/
