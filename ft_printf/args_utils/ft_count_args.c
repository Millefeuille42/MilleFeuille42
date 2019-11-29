/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 13:47:44 by mlabouri          #+#    #+#             */
/*   Updated: 2019/11/29 12:03:48 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int ft_val_arg(const char *s, size_t i)
{
	char	cur;
	char	flags[4];
	char	out[2];

	while ()
	{
		if (!(cur = ft_cinset(s[i], "-0.*")))
		{
			if (!(cur = ft_cinset(s[i], "-0.*")))
		}
		out = ft_val_flags(s, i ,cur);
		flags[out[0]] = out[1];
		i++;
	}
	return (0);
}