/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 15:39:06 by mlabouri          #+#    #+#             */
/*   Updated: 2019/10/17 15:22:31 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_gnl_line(char *buf, char **str, size_t *i, char flag)
{
	size_t offset;

	offset = *i;
	while(buf[*i] != '\n' && *i < BUFF_SIZE && buf[*i] != '\0')
		*i = *i + 1;
	if (flag == 0)
		*str = ft_substr(buf, 0, *i);
	else
		*str = ft_strjoin_limit(str, buf + offset, *i);
	if (!*str)
		return (100);
	if (buf[*i] == '\n' && *i < BUFF_SIZE)
		return (-1);
	if (buf[*i] == '\n' && *i == BUFF_SIZE)
		return (1);
	if (buf[*i] == '\0')
		return (2);
	return (0);
}

int		ft_gnl_end(char *buf, int status, int i)
{
	if (status == 2)
		return (0);
	return (1);
}

int		get_next_line(int fd, char **line)
{
	char		buf[BUFF_SIZE];
	char		*str;
	int			status;
	size_t		i;

	if (line == NULL || BUFF_SIZE == 0 || fd < 0)
		return (-1);
	i = 0;
	read(fd, buf, BUFF_SIZE);
	status = ft_gnl_line(buf, &str, &i), 0;
	while (status == 0)
	{
		read(fd, buf, BUFF_SIZE);
		status = ft_gnl_line(buf, &str, &i, 1);
	}
	if (status = 100)
		return (-1);
	(*line) = str;
	return (ft_gnl_end(buf, status, i));
}

int		main(void)
{
	fd = open("./test", O_RDONLY);
	return 0;
}
