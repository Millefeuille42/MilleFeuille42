/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 12:31:46 by mlabouri          #+#    #+#             */
/*   Updated: 2020/02/07 16:08:49 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		ft_printf(const char *input, ...)
{
	va_list				args;
	size_t				i;
	static	size_t		len;

	va_start(args, input);
	i = 0;
	len = ft_strlen(input);
	while (i < len)
	{
		i = ft_putstr_fd_c((char *) input, 1, '%', i);
		if (input[i] == '\0')
			return (0);
		i = ft_args((char *)input, i + 1, &args);
	}
	return (0);
}

int main(void)
{
	 ft_printf("\nBonsoir %s [%c] %% %3.4s test", "mlabouri", 'h', "tpabo");
		printf("\nBonsoir %s [%c] %% %3.4s test", "mlabouri", 'h', "tpabo");
}

//	TODO
//		- p conversion and length (min 0x)
//		- dot Flag (disp) !! PAD
//		- Counter implementation

//		0 : s, c, p		||	undefined behavior
//		* : *, digit	||	undefined behavior
//		. : -, p, c		||	undefined behavior