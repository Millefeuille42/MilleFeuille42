/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 16:14:23 by mlabouri          #+#    #+#             */
/*   Updated: 2019/11/14 17:54:43 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_gnl_join(size_t rsize, char **buf, char **str)
{
	int i;
	int status;

	if (rsize == 0)
	{
		*buf = NULL;
		return (1);
	}
	if (rsize < 0)
		return (-1);
	(*buf)[rsize] = '\0';
	i = 0;
	while ((*buf)[i] != '\n' && i < rsize)
		i++;
	if (!(*str = ft_strjoin_gnl(*str, *buf, i)))
		return (-1);
	if ((*buf)[i] == '\n' )
		status = 1;
	else
		status = 2;
	if (i < rsize)
		*buf = *buf + i + 1;
	return (status);
}

int		ft_gnl_newline(size_t rsize, char **buf, char **str)
{
	int i;
	int status;

	if (rsize == 0)
	{
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
	if (i < rsize)
		*buf = *buf + i + 1;
	return (status);
}

int		get_next_line(int fd, char **line)
{
	static char *buf;
	char *str;
	int status;

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

int		main(void)
{
	char **line;
	int value = 2;

	if (!(line = malloc(sizeof(char *))))
		return (3);
	int fd = open("./test.txt", O_RDONLY);

	while (value)
	{
		value = get_next_line(fd, line);
		printf("%s\n", line[0]);
	}
}