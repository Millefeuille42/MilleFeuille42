/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getcwd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 11:13:30 by dboyer            #+#    #+#             */
/*   Updated: 2020/10/09 11:26:38 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*getdir(size_t size)
{
	char	*path;

	if (!(path = ft_calloc(sizeof(char), size + 1)))
		return (NULL);
	if (size < 4096 && !getcwd(path, size))
	{
		safe_free((void **)&path);
		return (getdir(size + sizeof(char)));
	}
	else if (size >= 4096)
	{
		free(path);
		return (NULL);
	}
	return (path);
}

t_string	ft_getcwd(void)
{
	char		*dir;
	t_string	ret;

	dir = getdir(1);
	ret = ft_string(dir);
	safe_free((void **)&dir);
	return (ret);
}
