/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 16:14:23 by mlabouri          #+#    #+#             */
/*   Updated: 2019/11/21 18:36:52 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	**ft_buf_edit(size_t rsize, char **buf, size_t i)
{
	if (i < rsize)
		*buf = *buf + i + 1;
	if (i == rsize - 1)
	{
		//free(*buf);
		*buf = NULL;
	}
	return (buf);
}

int		ft_gnl_join(size_t rsize, char **buf, char **str)
{
	size_t	i;
	int		status;

	if (rsize == 0)
	{
		//free(*buf);
		*buf = NULL;
		return (1);
	}
	if (rsize < 0)
		return (-1);
	(*buf)[rsize] = '\0';
	i = 0;
	while ((*buf)[i] != '\n' && i < rsize)
		i++;
	if (!(*str = ft_strjoin_gnl(str, *buf, i)))
		return (-1);
	if ((*buf)[i] == '\n')
		status = 1;
	else
		status = 2;
	buf = ft_buf_edit(rsize, &(*buf), i);
	return (status);
}

int		ft_gnl_newline(size_t rsize, char **buf, char **str)
{
	size_t	i;
	int		status;

	if (rsize == 0)
	{
		//free(*buf);
		//free(*str);
		*buf = NULL;
		*str = NULL;
		return (0);
	}
	if (rsize < 0)
		return (-1);
	(*buf)[rsize] = '\0';
	i = 0;
	while ((*buf)[i] != '\n' && i < rsize)
		i++;
	if (!(*str = ft_substr(*buf, 0, i)))
		return (-1);
	if ((*buf)[i] == '\n')
		status = 1;
	else
		status = 2;
	buf = ft_buf_edit(rsize, buf, i);
	return (status);
}

int		get_next_line(int fd, char **line)
{
	static char	*buf;
	char		*tempbuf;
	char		*str;
	int			status;

	if (line == NULL || BUFFER_SIZE == 0 || fd < 0)
		return (-1);
	*line = NULL;
	if (buf)
		status = ft_gnl_newline(ft_strlen(buf), &buf, &str);
	else
	{
		if (!(buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
			return (-1);
		status = ft_gnl_newline(read(fd, buf, BUFFER_SIZE), &buf, &str);
	}
	while (status == 2)
		status = ft_gnl_join(read(fd, buf, BUFFER_SIZE), &buf, &str);
	if (status == 0)
		return (0);
	*line = str;
	return (status);
}

int		main(int ac, char **av)
{
	char	*line;
	int		fd;

	fd = ac > 1 ? open(av[1], O_RDONLY) : 0;
	while (get_next_line(fd, &line))
	{
		printf("%s\n", line);
		//free(line);
	}
	printf("%s\n", line);
	//free(line);
	//system("leaks a.out");
	close(fd);
	return (0);
}
