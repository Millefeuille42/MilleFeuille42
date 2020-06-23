/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 16:56:08 by dboyer            #+#    #+#             */
/*   Updated: 2020/06/16 17:00:52 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_env(t_shell *shell, char *argv[])
{
	size_t argc;

	argc = ft_len(argv);
	if (argc == 1)
	{
		shell->print_env(shell);
		return (0);
	}
	ft_printf("env: too much arguments\n");
	return (1);
}
