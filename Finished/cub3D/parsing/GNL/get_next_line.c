/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 14:06:41 by mlabouri          #+#    #+#             */
/*   Updated: 2020/05/18 11:12:44 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/get_next_line.h"

inline static	int		ft_ginit(char **line, char **buffer, int fd)
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

inline static	int		ft_gline(char **buffer, int fd)
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
		*buffer = ft_gstrjoin(*buffer, buf);
		free(cpy_buffer);
		if (!*buffer)
			return (-1);
		if (ft_gstrchr(buf, '\n'))
			break ;
	}
	if (rsize == 0 && !(ft_gstrchr(*buffer, '\n')))
		return (0);
	return (1);
}

inline static	int		ft_gmake(char **buffer, char **line)
{
	int		i;
	char	*cpy_buffer;

	i = 0;
	while ((*buffer)[i] != '\n' && (*buffer)[i] != '\0')
		i++;
	*line = ft_gsubstr(*buffer, 0, i);
	if ((*buffer)[i] != '\0')
		i++;
	cpy_buffer = ft_gsubstr(*buffer, i, ft_gstrlen(*buffer));
	free(*buffer);
	if (!cpy_buffer)
		return (-1);
	*buffer = cpy_buffer;
	return (0);
}

int						get_next_line(int fd, char **line)
{
	static char	*buffer;
	int			status;

	if (ft_ginit(line, &buffer, fd) == -1)
		return (-1);
	if ((status = ft_gline(&buffer, fd)) == -1)
		return (-1);
	if (buffer[0] != '\0')
	{
		if (ft_gmake(&buffer, line) == -1)
			return (-1);
		if (buffer[0] == '\0')
		{
			free(buffer);
			buffer = NULL;
		}
		return (status);
	}
	free(buffer);
	*line = ft_gsubstr("\0", 0, 1);
	return (0);
}
