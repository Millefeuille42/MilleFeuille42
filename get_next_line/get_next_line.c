/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 16:54:07 by mlabouri          #+#    #+#             */
/*   Updated: 2019/11/25 17:04:01 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	int		ft_init(char **line, char **buffer, int fd)
{
	int i;

	if (fd == -1 || line == NULL || BUFFER_SIZE == 0 || BUFFER_SIZE > 8000000)
		return (-1);
	if (!*buffer)
	{
		if (!(*buffer = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
			return (-1);
		i = 0;
		while (i < (BUFFER_SIZE + 1))
		{
			buffer[i] = 0;
			i++;
		}
	}
	return (0);
}

static	int		ft_make_joinline(size_t size, char **buf, char **line)
{

}

static	int		ft_line(char **buffer, char **line, int fd)
{
	char	buf[BUFFER_SIZE + 1];
	char	*cpy_buffer;
	size_t	rsize;

	while ((rsize = read(fd, buf, BUFFER_SIZE) != 0))
	{
		if (rsize < 0)
			return (-1);
		buf[rsize] = '\0';
		cpy_buffer = *buffer;
		ft_strjoin(*buffer, buf);
		free(cpy_buffer);
		if (!*buffer)
			return (-1);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (rsize == 0)
		return (0);
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char	*buffer;

	if (ft_init(line, &buffer, fd) == -1)
		return (-1);

}

int		main(int ac, char **av)
{
	char	*line;
	int		fd;

	fd = ac > 1 ? open(av[1], O_RDONLY) : 0;
	while (get_next_line(fd, &line) > 0)
	{
		printf("%s\n", line);
		free(line);
	}
	printf("%s\n", line);
	free(line);
	//system("leaks a.out");
	close(fd);
	return (0);
}