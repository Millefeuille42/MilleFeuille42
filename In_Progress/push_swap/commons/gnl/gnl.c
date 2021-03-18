#include "../includes/commons.h"

static int	ft_init(char **line, char **mem_buffer, int fd)
{
	int		i;
	char	read_buffer[4];

	if (fd <= -1 || line == NULL)
		return (-1);
	if (read(fd, read_buffer, 0))
		return (-1);
	if (!*mem_buffer)
	{
		*mem_buffer = malloc(sizeof(char) * 4);
		if (!(*mem_buffer))
			return (-1);
		i = 0;
		while (i < 4)
		{
			(*mem_buffer)[i] = '\0';
			i++;
		}
	}
	return (0);
}

static int	ft_read_line(char **mem_buffer, int fd)
{
	char	read_buffer[4];
	char	*copy_buffer;
	size_t	r_size;

	r_size = -1;
	while (r_size)
	{
		r_size = read(fd, read_buffer, 3);
		if (r_size < 0)
			return (-1);
		read_buffer[r_size] = '\0';
		copy_buffer = *mem_buffer;
		*mem_buffer = ft_strjoin(*mem_buffer, read_buffer);
		free(copy_buffer);
		if (!*mem_buffer)
			return (-1);
		if (ft_strchr(read_buffer, '\n'))
			break ;
	}
	if (r_size == 0 && !(ft_strchr(*mem_buffer, '\n')))
		return (0);
	return (1);
}

static int	ft_extract(char **mem_buffer, char **line)
{
	int		i;
	char	*copy_buffer;

	i = 0;
	while ((*mem_buffer)[i] != '\n' && (*mem_buffer)[i] != '\0')
		i++;
	*line = ft_substr(*mem_buffer, 0, i);
	if ((*mem_buffer)[i] != '\0')
		i++;
	copy_buffer = ft_substr(*mem_buffer, i, ft_strlen(*mem_buffer));
	free(*mem_buffer);
	if (!copy_buffer)
		return (-1);
	*mem_buffer = copy_buffer;
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*mem_buffer;
	int			status;

	if (ft_init(line, &mem_buffer, fd) == -1)
		return (-1);
	status = ft_read_line(&mem_buffer, fd);
	if (status == -1)
		return (status);
	if (mem_buffer[0] != '\0')
	{
		if (ft_extract(&mem_buffer, line) == -1)
			return (-1);
		if (mem_buffer[0] == '\0')
		{
			free(mem_buffer);
			mem_buffer = NULL;
		}
		return (status);
	}
	free(mem_buffer);
	*line = ft_substr("\0", 0, 1);
	return (0);
}
