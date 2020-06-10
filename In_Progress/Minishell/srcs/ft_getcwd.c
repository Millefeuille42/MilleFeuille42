/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getcwd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 11:13:30 by dboyer            #+#    #+#             */
/*   Updated: 2020/06/10 11:45:24 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

static inline char *getdir(size_t size)
{
    char *path;

    if (!(path = malloc(sizeof(char) * (size + 1))))
        return NULL;
    if (!getcwd(path, size))
    {
        free(path);
        return (getdir(size + sizeof(char)));
    }
    return (path);
}

char *ft_getcwd(void)
{
    return (getdir(1));
}
