/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 14:06:41 by mlabouri          #+#    #+#             */
/*   Updated: 2020/04/30 18:34:45 by millefeui        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	int		ft_init(char **line, char **buffer, int fd)
{
	int		i;
	char	buf[BUFFER_SIZE + 1];

	if (fd == -1 || line == NULL || BUFFER_SIZE == 0 || BUFFER_SIZE > 8000000)
		return (-1);
	if (read(fd, buf, 0))
		return (-1);
	if (!*buffer)
	{
		if (!(*buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
			return (-1);
		i = 0;
		while (i < (BUFFER_SIZE + 1))
		{
			(*buffer)[i] = '\0';
			i++;
		}
	}
	return (0);
}

static	int		ft_line(char **buffer, int fd)
{
	char	buf[BUFFER_SIZE + 1];
	char	*cpy_buffer;
	size_t	rsize;

	rsize = -1;
	while (rsize != 0)
	{
		rsize = read(fd, buf, BUFFER_SIZE);
		if (rsize < 0)
			return (-1);
		buf[rsize] = '\0';
		cpy_buffer = *buffer;
		*buffer = ft_strjoin(*buffer, buf);
		free(cpy_buffer);
		if (!*buffer)
			return (-1);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (rsize == 0 && !(ft_strchr(*buffer, '\n')))
		return (0);
	return (1);
}

static	int		ft_make(char **buffer, char **line)
{
	int		i;
	char	*cpy_buffer;

	i = 0;
	while ((*buffer)[i] != '\n' && (*buffer)[i] != '\0')
		i++;
	*line = ft_substr(*buffer, 0, i);
	if ((*buffer)[i] != '\0')
		i++;
	cpy_buffer = ft_substr(*buffer, i, ft_strlen(*buffer));
	free(*buffer);
	if (!cpy_buffer)
		return (-1);
	*buffer = cpy_buffer;
	return (0);
}

int				get_next_line(int fd, char **line)
{
	static char	*buffer[];
	int			status;

	if (ft_init(line, &buffer[fd], fd) == -1)
		return (-1);
	if ((status = ft_line(&buffer[fd], fd)) == -1)
		return (-1);
	if (buffer[fd][0] != '\0')
	{
		if (ft_make(&buffer[fd], line) == -1)
			return (-1);
		if (buffer[fd][0] == '\0')
		{
			free(buffer[fd]);
			buffer[fd] = NULL;
		}
		return (status);
	}
	free(buffer[fd]);
	*line = ft_substr("\0", 0, 1);
	return (0);
}
