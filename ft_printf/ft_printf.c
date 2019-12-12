/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 12:31:46 by mlabouri          #+#    #+#             */
/*   Updated: 2019/12/12 17:09:46 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *input, ...)
{
	va_list	args;
	unsigned long long arg;
	size_t	i;

	va_start(args, input);
	i = 0;

	while (input[i] != '\0')
	{
		i = ft_putstr_fd_c((char *)input, 1, '%');
		if (input[i] == '\0')
			return (0);
		arg = va_arg(args, unsigned long long);
		i = ft_args((char *)input, i + 1, arg);
		input = input + i;
		i = 0;
	}
	return (0);
}

int main(void)
{
	ft_printf("Bonsoir \n%s je suis test [%c]\n", "mlabouri", 'h');
//	printf("Test : %.9d", 765644);
}

//	TODO
//		- 0x = ADD x - int length 0 to the left of the int
//		-