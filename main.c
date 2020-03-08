#include "cub3D/cub3d.h"

int main(void)
{
	int fd;
	struct s_conf conf;

	printf("pro");
	fd = open("./sample.cub", O_RDONLY);
	cub_parser(fd, &conf);
}