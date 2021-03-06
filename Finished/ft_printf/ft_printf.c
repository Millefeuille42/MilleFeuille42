/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 14:06:41 by mlabouri          #+#    #+#             */
/*   Updated: 2020/05/07 12:19:21 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/trees.h"

int						g_count;
int						(*g_func_length[255])(char, struct s_c, struct s_f *);
void					(*g_func_conv[255])(struct s_c);

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
			break ;
		i = ft_args((char *)input, i + 1, &args);
	}
	va_end(args);
	return (g_count);
}
