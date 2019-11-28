/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 13:47:44 by mlabouri          #+#    #+#             */
/*   Updated: 2019/11/28 15:20:47 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdio.h>

int ft_val_arg(const char *s, size_t i)
{
	char	cur;
	if ((cur = ft_cinset(s[i + 1], "-0.*")))
		return (ft_val_flags(s, i ,cur));
	return (0);
}

size_t		ft_count_args(const char *s)
{
	size_t	i;
	size_t	count;
	int		status;

	i = 0;
	count = 0;
	if (ft_strlen(s) <= 1)
		return (1);
	while (s[i] != '\0')
	{
		if (s[i] == '%' && (status = ft_val_arg(s, i)) != 0)
		{
			count++;
			i = i + (size_t)status;
		}
		else
			i++;
	}
	return (count);
}

int main(void)
{
	printf("%zu", ft_count_args("%D awf"));
}