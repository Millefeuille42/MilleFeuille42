/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 12:31:46 by mlabouri          #+#    #+#             */
/*   Updated: 2019/12/20 15:02:33 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *input, ...)
{
	va_list				args;
	unsigned long long	arg;
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
		arg = va_arg(args, unsigned long long);
		i = ft_args((char *)input, i + 1, arg);
	}
	return (0);
}

int main(void)
{
	ft_punbrbase(4667, HEX);
	//	ft_printf("Bonsoir %s je suis test [%c]yes %% %bir", "mlabouri", 'h');
	//	printf("Bonsoir %s je suis test [%c]yes %% %bir", "mlabouri", 'h');
	//	printf("Test : %.9d", 765644);
}

//	TODO
//		- 0x = ADD x - int length 0 to the left of the int
//		-