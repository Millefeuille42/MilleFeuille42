/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:44:24 by mlabouri          #+#    #+#             */
/*   Updated: 2020/02/10 10:19:27 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t	ft_putstr_fd_c(char *s, int fd, char c, size_t i)
{
	if (fd < 0 || !s)
		return (-1);
	while (s[i] != '\0' && s[i] != c)
	{
		write(fd, &s[i], 1);
		i++;
		g_count++;
	}
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	if (fd < 0 || !s)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
		g_count++;
	}
}

void	ft_putnstr(char *s, int len)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && i < len)
	{
		write(1, &s[i], 1);
		i++;
		g_count++;
	}
}
