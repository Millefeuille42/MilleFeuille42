/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 17:09:36 by dboyer            #+#    #+#             */
/*   Updated: 2020/06/12 08:48:05 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static inline void	clear_element(t_element *element)
{
	free(element->content);
}

void				ft_clear_env(t_shell *shell)
{
	if (shell->env.size)
	{
		shell->env.iter(shell->env.first, clear_element);
		shell->env.clear(&shell->env);
	}
}
