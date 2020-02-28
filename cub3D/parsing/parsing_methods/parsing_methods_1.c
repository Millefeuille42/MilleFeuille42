
#include "../../cub3d.h"

int	res_p(struct s_cub *conf, char *line)
{
	int i;
	int i2;

	i = 2;
	if (line[i] != ' ' && !(ft_isdigit(line[i])))
		return (-2);
	while (line[i] == ' ' && line[i])
		i++;
	i2 = i;
	while (ft_isdigit(line[i2]))
		i2++;
	if (line[i2] != ' ')
		return (-2);
	conf->res.x = atoi_mk2(line, i, i2 - 1);
	i = i2;
	while (line[i] == ' ' && line[i])
		i++;
	i2 = i;
	while (ft_isdigit(line[i2]))
		i2++;
	if (!(ft_cinset(line[i2], " \n\t\r")))
		return (-2);
	conf->res.y = atoi_mk2(line, i, i2 -1);
}

int	floor_p(struct s_cub *conf, char *line)
{
	int i;
	int i2;

	i = 2;
	if (line[i] != ' ' && !(ft_isdigit(line[i])))
		return (-2);
	while (line[i] == ' ' && line[i])
		i++;



}

static int rgb_parsing(struct s_cub *conf, int *i, char *line)
{
	int i2;

	i2 = *i;
	while (ft_isdigit(line[i2]))
		i2++;
	if (!(ft_cinset(line[i2], ", ")))
		return (-2);
	conf->floor.r = atoi_mk2(line, *i, i2 - 1);
	while (ft_cinset(line[i2], ", "))
		*i = *i + 1;
}