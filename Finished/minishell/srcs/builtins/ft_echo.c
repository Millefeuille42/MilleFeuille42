/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 11:34:48 by mlabouri          #+#    #+#             */
/*   Updated: 2020/09/29 11:34:48 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_echo(char *argv[])
{
	int		i;
	int		argc;
	char	n;
	char	flag;

	i = 1;
	flag = 0;
	n = 1;
	argc = ft_len(argv);
	while (argv[i])
	{
		if (!flag && ft_str_isequal("-n", argv[i]))
			n = 0;
		else
		{
			flag = 1;
			ft_putstr(argv[i]);
			if (i < argc - 1)
				ft_putchar(' ');
		}
		i++;
	}
	if (n == 1)
		ft_putchar('\n');
	return (0);
}
