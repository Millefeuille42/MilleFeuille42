/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 17:26:10 by dboyer            #+#    #+#             */
/*   Updated: 2020/06/23 17:00:30 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static  int	condition(t_element *element, void *key)
{
	t_env	*content;
	char	*key_in_list;

	content = (t_env *)element->content;
	key_in_list = (char *)content->key;
	return (ft_str_isequal(key_in_list, (char *)key));
}

char				*ft_env_get(t_shell *shell, char *key)
{
	t_element	*element;
	t_env		*content;

	if (shell->env.size)
	{
		element = shell->env.search(shell->env.first, key, condition);
		if (element)
		{
			content = (t_env *)element->content;
			return ((char *)content->value);
		}
	}
	return (NULL);
}
