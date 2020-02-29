
#include "../../cub3d.h"

static int safe_join(char **s1, char **s2)
{
	char *temp;
	char *temp2;
	int err;

	if (!(temp = ft_strjoin(*s1, *s2)))
		return (-3);
	temp2 = ft_strjoin(temp, "\n");
	free(temp);
	if (temp2 == NULL)
		return (-3);
	free(*s1);
	*s1 = ft_strdup(temp2);
	free(temp2);
	if (*s1 == NULL)
		return (-3);
	return (0);
}

int map_p(struct s_cub *conf, int fd)
{
	int err;
	char *line;
	char *final;

	final = NULL;
	while ((err = get_next_line(fd, &line)))
	{
		if (err == -1 || (err = safe_join(&final, &line)))
			break ;
		free(line);
	}
	if (!(err))
		err = safe_join(&final, &line);
	free(line);
	if (err)
	{
		free(final);
		return (-3);
	}
	conf->map = final;
	return (0);
}