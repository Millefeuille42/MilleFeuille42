/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 12:31:46 by mlabouri          #+#    #+#             */
/*   Updated: 2019/12/24 11:12:21 by null             ###   ########.fr       */
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
		ft_printf("%Bonsoir %s je suis test [%c] yes %% %d files", "mlabouri", 'h', 32);
		printf("\nBonsoir %s je suis test [%c] yes %% %010d files", "mlabouri", 'h', 32);
	//	printf("Test : %.9d", 765644);
}

//	TODO
//		- 0x = ADD x - int length 0 to the left of the int
//		-