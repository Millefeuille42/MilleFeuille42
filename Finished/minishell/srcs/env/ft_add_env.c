/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 15:42:12 by dboyer            #+#    #+#             */
/*   Updated: 2020/10/21 17:38:25 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	int	compare(t_element *element, void *content)
{
	t_env	*env;

	env = (t_env *)element->content;
	return (ft_strncmp(env->key, content, ft_strlen(env->key)) > 0);
}

void		ft_add_env(t_shell *shell, char *key, char *value)
{
	t_env		*new;
	t_element	*element;

	if ((new = (t_env *)ft_calloc(sizeof(t_env), 1)))
	{
		new->key = key;
		new->value = value;
		element = shell->env.search(shell->env.first, key, compare);
		if (element)
			shell->env.insert_before(&shell->env, element, new);
		else
			shell->env.append(&shell->env, new);
	}
}
