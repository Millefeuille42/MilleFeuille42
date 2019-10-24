/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 15:39:06 by mlabouri          #+#    #+#             */
/*   Updated: 2019/10/24 10:48:04 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#ifdef FIRST_CALL
# define FIRST_CALL 1
#endif
#ifndef FIRST_CALL
# define FIRST_CALL 1
#endif

int		ft_gnl_line(size_t rsize, char *buf, char **str, size_t *i)
{
	*i = 0;
	if (rsize == 0)
		return (2);
	if (rsize < 0)
		return (100);
	while (buf[*i] != '\n' && *i < rsize)
		*i = *i + 1;
	if (!*str)
		*str = ft_substr(buf, 0, *i);
	else
		*str = ft_strjoin_gnl(*str, buf, *i);
	if (!*str)
		return (100);
	if (buf[*i] == '\n' && *i < rsize)
		return (-1);
	if (buf[*i] == '\n' && *i == rsize)
		return (1);
	return (0);
}

int		ft_gnl_memory(char **memory, char **str, size_t *i)
{
	size_t len;

	*i = 0;
	len = ft_strlen(*memory);
	while (*memory[*i] != '\n' && *i < len)
		*i = *i + 1;
	*str = ft_substr(*memory, 0, *i);
	if (!*str)
		return (100);
	if (*memory[*i] == '\n' && *i < len)
	{
		*memory[*i] = '\0';
		return (-11);
	}
	if (*memory[*i] == '\n' && *i == len)
		return (1);
	return (0);
}

int		ft_gnl_end(char *buf, int status, char **memory, size_t i)
{
	char	*temp;

	if (status == 2)
	{
		free(*memory);
		return (0);
	}
	if (status == -1)
	{
		free(*memory);
		*memory = ft_strdup(buf + i);
	}
	if (status == -11)
	{
		temp = ft_strdup(*memory + ft_strlen(*memory));
		free(*memory);
		*memory = ft_strdup(temp);
		free(temp);
	}
	if (!*memory)
		return (-1);
	return (1);
}

int		get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE];
	char		*str;
	int			status;
	size_t		i;
	static char *memory;

	if (line == NULL || BUFFER_SIZE == 0 || fd < 0)
		return (-1);
	str = NULL;
	if (!FIRST_CALL)
		memory = NULL;
	if (memory)
		status = ft_gnl_memory(&memory, &str, &i);
	else
		status = ft_gnl_line(read(fd, buf, BUFFER_SIZE), buf, &str, &i);
	while (status == 0)
		status = ft_gnl_line(read(fd, buf, BUFFER_SIZE), buf, &str, &i);
	if (status == 100)
		return (-1);
	(*line) = str;
	return (ft_gnl_end(buf, status, &memory, i));
}
