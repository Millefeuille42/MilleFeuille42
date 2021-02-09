/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 16:39:39 by dboyer            #+#    #+#             */
/*   Updated: 2020/10/27 16:13:14 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	unset(t_shell *shell, char **envp)
{
	int i;

	i = 0;
	while (envp[i])
	{
		shell->env_remove(shell, envp[i]);
		i++;
	}
}

static char	*check_args(char **envp)
{
	int i;

	i = 0;
	while (envp[i])
	{
		if (ft_cinset('=', envp[i]))
			return (envp[i]);
		i++;
	}
	return (NULL);
}

int			ft_unset(t_shell *shell, char *argv[])
{
	size_t	argc;
	char	*arg_checked;

	argc = ft_len(argv);
	if (argc == 1)
	{
		ft_putstr_fd("unset : not enough arguments\n", STDERR_FILENO);
		return (1);
	}
	if ((arg_checked = check_args(argv)))
	{
		ft_print_error("unset: %s: invalid parameter name\n", arg_checked[0]);
		return (1);
	}
	unset(shell, argv);
	return (0);
}
