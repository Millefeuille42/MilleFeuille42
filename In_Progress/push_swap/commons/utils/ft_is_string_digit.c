//
// Created by millefeuille on 15/03/2021.
//

#include "../includes/commons.h"

int	ft_is_string_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
