//
// Created by Millefeuille on 11/06/2021.
//

#include "../minitalk.h"

void	ft_putstr(const char *str)
{
	if (!str)
		return ;
	while (*str)
		write(1, &*str++, 1);
}
