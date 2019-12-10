/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:44:24 by mlabouri          #+#    #+#             */
/*   Updated: 2019/12/10 12:33:00 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

size_t ft_putstr_fd_c(const char *s, int fd, char c)
{
	size_t	i;

	if (fd < 0 || !s)
		return (-1);
	i = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		write(fd, &s[i], 1);
		i++;
	}
	return (i);
}
