/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 15:39:06 by mlabouri          #+#    #+#             */
/*   Updated: 2019/10/18 16:56:33 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_gnl_line(size_t rsize, char *buf, char **str)
{
	size_t i;

	i = 0;
	if (rsize == 0)
		return (2);
	if (rsize < 0)
		return (100);
	while (buf[i] != '\n' && i < rsize)
		i++;
	if (!*str)
		*str = ft_substr(buf, 0, i);
	else
		*str = ft_strjoin_limit(*str, buf, i);
	printf("%zu _ %zu		%s$\n", rsize, i, *str);
	if (!*str)
		return (100);
	if (buf[i] == '\n' && i < rsize)
		return (-1);
	if (buf[i] == '\n' && i == rsize)
		return (1);
	if (rsize < BUFFER_SIZE)
		return (2);
	return (0);
}

int		ft_gnl_end(char *buf, int status)
{
	buf = NULL;
	if (status == 2)
		return (0);
	return (1);
}

int		get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE];
	char		*str;
	int			status;

	if (line == NULL || BUFFER_SIZE == 0 || fd < 0)
		return (-1);
	str = NULL;
	if (memory)
	
	status = ft_gnl_line(read(fd, buf, BUFFER_SIZE), buf, &str);
	while (status == 0)
		status = ft_gnl_line(read(fd, buf, BUFFER_SIZE), buf, &str);
	if (status == 100)
		return (-1);
	printf("\nSTRING	=	%s$\n", str);
	(*line) = str;
	return (ft_gnl_end(buf, status));
}

int		main(void)
{
	char **line;
	int fd;

	line = malloc(sizeof(char *));
	fd = open("./test", O_RDONLY);
	printf("CODE	=	%d\n", get_next_line(fd, line));
	return (0);
}
