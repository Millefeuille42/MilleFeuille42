
#include "../../cub3d.h"

int res_e(struct s_res res)
{
	// TODO
	//		- MiniLibX Resolution

	if (res.x <= 0 || res.y <= 0)
		return (-2);
	return (0);
}

int rgb_e(struct s_plan plan)
{
	if (plan.r > 255 || plan.g > 255 || plan.b > 255)
		return (-2);
	return (0);
}