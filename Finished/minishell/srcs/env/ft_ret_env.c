/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ret_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 19:24:46 by dboyer            #+#    #+#             */
/*   Updated: 2020/10/09 19:24:53 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_ret_env(t_shell *shell)
{
	t_element	*cur;
	char		**envs;
	char		*key;
	int			i;

	if (!(envs = ft_calloc(sizeof(char *), shell->env.size + 1)))
		return (NULL);
	cur = shell->env.first;
	i = 0;
	while (cur)
	{
		key = ft_strjoin(((t_env *)cur->content)->key, "=");
		envs[i] = ft_strjoin(key, ((t_env *)cur->content)->value);
		safe_free((void **)&key);
		i++;
		cur = cur->next;
	}
	envs[i] = NULL;
	return (envs);
}
