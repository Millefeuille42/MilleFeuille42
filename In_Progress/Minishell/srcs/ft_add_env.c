/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 15:42:12 by dboyer            #+#    #+#             */
/*   Updated: 2020/06/12 12:26:34 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_add_env(t_shell *shell, char *key, char *value)
{
	t_env *new;

	if ((new = (t_env *)malloc(sizeof(t_env))))
	{
		new->key = key;
		new->value = value;
		shell->env.append(&shell->env, new);
	}
}
