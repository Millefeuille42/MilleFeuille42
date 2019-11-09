/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:46:59 by mlabouri          #+#    #+#             */
/*   Updated: 2019/11/05 15:00:04 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//fd incorrect ?

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	size_t	i;

	if (s)
	{
		i = 0;
		while (s[i] != '\0')
		{
			write(fd, &s[i], 1);
			i++;
		}
		write(fd, "\n", 1);
	}
}
