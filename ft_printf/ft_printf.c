/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 12:31:46 by mlabouri          #+#    #+#             */
/*   Updated: 2020/02/10 10:21:19 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int g_count;

int	ft_printf(const char *input, ...)
{
	va_list				args;
	size_t				i;
	static	size_t		len;

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

int	main(void)
{
	int ret;
	int ret2;

	ret = ft_printf("Bonsoir %s [%c] %% %.9X", "mlabouri", 'h', -1234);
	ret2 = printf("Bonsoir %s [%c] %% %.9X", "mlabouri", 'h', -1234);
	printf("\nUSER : %d \nNORM : %d", ret, ret2);
}

/*
	* TODO
	*		- p conversion and length (min 0x)
	*
	*		0 : s, c, p		||	undefined behavior
	*		* : *, digit	||	undefined behavior
	*		. : -, p, c		||	undefined behavior
*/
