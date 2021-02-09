/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 11:28:23 by dboyer            #+#    #+#             */
/*   Updated: 2020/10/09 11:28:29 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_start_env(t_shell *shell_ng, char **envp)
{
	int		i;
	char	**splitted;

	i = 0;
	while (envp[i])
	{
		splitted = ft_extract_env(envp[i]);
		if (splitted)
		{
			shell_ng->add_env(shell_ng, splitted[0], splitted[1]);
			safe_free((void **)&splitted);
		}
		i++;
	}
}
