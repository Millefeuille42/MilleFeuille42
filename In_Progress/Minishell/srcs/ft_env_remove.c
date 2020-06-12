/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_remove.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 17:26:10 by dboyer            #+#    #+#             */
/*   Updated: 2020/06/12 09:00:13 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static inline int	condition(t_element *element, void *key)
{
	t_env	*content;
	char	*key_in_list;

	content = (t_env *)element->content;
	key_in_list = (char *)content->key;
	return (ft_str_isequal(key_in_list, (char *)key));
}

void				ft_env_remove(t_shell *shell, char *key)
{
	t_element	*element;

	if (shell->env.size)
	{
		element = shell->env.search(shell->env.first, key, condition);
		if (element)
		{
			free(element->content);
			shell->env.remove(&shell->env, element);
		}
	}
}
