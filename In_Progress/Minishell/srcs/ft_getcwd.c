/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getcwd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 11:13:30 by dboyer            #+#    #+#             */
/*   Updated: 2020/06/10 17:29:06 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static inline char	*getdir(size_t size)
{
	char	*path;

	if (!(path = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	if (!getcwd(path, size))
	{
		free(path);
		return (getdir(size + sizeof(char)));
	}
	return (path);
}

t_string			ft_getcwd(void)
{
	char		*dir;
	t_string	ret;

	dir = getdir(1);
	ret = ft_string(dir);
	free(dir);
	return (ret);
}
