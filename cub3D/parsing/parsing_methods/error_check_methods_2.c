
#include "../../cub3d.h"

static int linecount(char *map)
{
	int i;
	int lines;

	i = 0;
	lines = 0;
	while (map[i] != '\0')
	{
		while (map[i] != '\n' && map[i] != '\0')
			i++;
		lines++;
	}
}

int map_e(char *map)
{
	int len;
	int lines;
	int i[2];

	i[0] = 0;
	lines = 0;

	if (lines < 3)
		return (-2);
	return (0);
}