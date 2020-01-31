/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 12:31:46 by mlabouri          #+#    #+#             */
/*   Updated: 2020/01/31 09:16:35 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		ft_printf("\nBonsoir %s je suis test [%c] %% %0*5-*s files", "mlabouri", 'h', 6, 7, "1234");
		printf("\nBonsoir %s je suis test [%c] %% %0*5-*s files", "mlabouri", 'h', 6, 7, "1234");
}

//	TODO
//		- u conversion and length
//		- p conversion and length
//		- dot Flag