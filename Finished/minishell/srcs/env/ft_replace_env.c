/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 12:14:27 by mlabouri          #+#    #+#             */
/*   Updated: 2020/09/29 12:14:27 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_replace_env(t_shell *shell, char *key, char *value)
{
	if (shell->env_get(shell, key))
		shell->env_remove(shell, key);
	shell->add_env(shell, key, value);
}
