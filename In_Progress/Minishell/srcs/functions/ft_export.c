/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 15:01:46 by dboyer            #+#    #+#             */
/*   Updated: 2020/06/16 16:39:14 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

inline static void	update_env(t_shell *shell, char *key, char *value)
{
	char *val;

	val = shell->env_get(shell, key);
	if (val)
		shell->env_remove(shell, key);
	shell->add_env(shell, key, value);
}

inline static void	export(t_shell *shell, char **envp)
{
	int		i;
	char	**splitted;

	i = 1;
	while (envp[i])
	{
		splitted = ft_extract_env(envp[i]);
		if (splitted)
		{
			update_env(shell, splitted[0], splitted[1]);
			free(splitted);
		}
		else if (ft_cinset('=', envp[i]))
			update_env(shell, ft_strdup(envp[i]), NULL);
		i++;
	}
}

int					ft_export(t_shell *shell, char *argv[])
{
	size_t argc;

	argc = ft_len(argv);
	if (argc == 1)
	{
		shell->print_env(shell);
		return (0);
	}
	export(shell, argv);
	return (0);
}
