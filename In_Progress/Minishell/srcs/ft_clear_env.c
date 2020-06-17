/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 17:09:36 by dboyer            #+#    #+#             */
/*   Updated: 2020/06/15 11:34:26 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static inline void	clear_element(t_element *element)
{
	t_env	*content;

	content = (t_env *)element->content;
	if (content->value)
	{
		free(content->value);
		content->value = NULL;
	}
	if (content->key)
	{
		free(content->key);
		content->key = NULL;
	}
	free(content);
}

void				ft_clear_env(t_shell *shell)
{
	if (shell->env.size)
	{
		shell->env.iter(shell->env.first, clear_element);
		shell->env.clear(&shell->env);
	}
}
