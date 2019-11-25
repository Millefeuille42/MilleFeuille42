/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 16:54:07 by mlabouri          #+#    #+#             */
/*   Updated: 2019/11/23 19:00:51 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_clean(char **line, char **buf, int status)
{

	if (status <= -1)
	{
		ft_safe_free((void **)buf);
		ft_safe_free((void **)line);
	}
	if (status == 0)
		ft_safe_free((void **)buf);
	return (status);
}

int		ft_make_joinline(size_t size, char **buf, char **line)
{
	size_t	i;
	int		status;

	status = 2;
	if (size == 0)
	{
		ft_safe_free((void **)buf);
		return (0);
	}
	if (size <= 0)
		return (-1);
	(*buf)[size] = '\0';
	i = 0;
	while ((*buf)[i] != '\n' && (*buf)[i] != '\0')
		i++;
	if (!(*line = ft_strjoin_gnl(line, *buf, i)))
		return (-1);
	if ((*buf)[i] == '\n')
	{
		status = 1;
		if (!(*buf = ft_strdup_gnl(buf, i + 1)))
			return (-1);
	}
	return (status);
}

int		ft_make_newline(size_t size, char **buf, char **line)
{
	size_t	i;
	int		status;

	status = 2;
	if (size == 0)
	{
		ft_safe_free((void **)buf);
		*line = ft_substr("", 0, 10);
		return (0);
	}
	if (size <= 0)
		return (-1);
	(*buf)[size] = '\0';
	i = 0;
	while ((*buf)[i] != '\n' && (*buf)[i] != '\0')
		i++;
	if (!(*line = ft_substr(*buf, 0, i)))
		return (-1);
	if ((*buf)[i] == '\n')
	{
		status = 1;
		if (!(*buf = ft_strdup_gnl(buf, i + 1)))
			return (-1);
	}
	return (status);
}

int		get_next_line(int fd, char **line)
{
	static char	*buf;
	int			status;

	if (line == NULL || BUFFER_SIZE == 0 || fd < 0)
		return (-1);
	if (buf && ft_strlen(buf) == 0)
		ft_safe_free((void **)&buf);
	*line = NULL;
	if (!buf)
	{
		if (!(buf = malloc(sizeof(char) * (BUFFER_SIZE + sizeof(char)))))
			return (-1);
		status = ft_make_newline(read(fd, buf, BUFFER_SIZE), &buf, line);
	}
	else
		status = ft_make_newline(ft_strlen(buf), &buf, line);
	while (status == 2)
		status = ft_make_joinline(read(fd, buf, BUFFER_SIZE), &buf, line);
	return (ft_clean(line, &buf, status));
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