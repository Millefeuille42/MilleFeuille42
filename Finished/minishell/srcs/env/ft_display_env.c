/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 15:48:06 by dboyer            #+#    #+#             */
/*   Updated: 2020/10/09 11:27:23 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	void	display(t_element *element)
{
	t_env *env;

	env = (t_env *)element->content;
	if (*env->key != '?')
	{
		ft_putstr(env->key);
		ft_putchar('=');
		ft_putstr(env->value);
		ft_putchar('\n');
	}
}

void			ft_display_env(t_shell *shell)
{
	shell->env.iter(shell->env.first, display);
}
