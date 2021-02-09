/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 10:59:09 by dboyer            #+#    #+#             */
/*   Updated: 2020/10/27 16:27:16 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	int	ft_isnumeric(char *str)
{
	int	minus;

	minus = 0;
	if (str)
	{
		while (str++ && *str)
		{
			if ((*str == '-' && minus > 1) || \
					(!ft_isdigit(*str) && *str != '-'))
				return (0);
			minus = *str == '-' ? minus + 1 : minus;
		}
		return (1);
	}
	return (0);
}

static	int	add_exit_code(t_shell *shell, int exit, int exit_code)
{
	shell->exit = exit;
	shell->exit_code = exit_code;
	return (0);
}

int			ft_exit(t_shell *shell, char **argv)
{
	size_t	len;

	len = ft_len(argv);
	if (len == 1)
		return (add_exit_code(shell, 1, 0));
	if (len == 2 && ft_isnumeric(argv[1]))
		return (add_exit_code(shell, 1, ft_atoi(argv[1])));
	if (len == 2 && !ft_isnumeric(argv[1]))
	{
		ft_print_error(\
		"minishell: exit: %s : argument numérique nécessaire\n", argv[1]);
		return (1);
	}
	if (len > 2)
	{
		ft_putstr_fd("minishell: exit: trop d'arguments\n", STDERR_FILENO);
		return (1);
	}
	return (0);
}
