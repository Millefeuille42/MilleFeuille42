#include "../includes/graphical.h"

void rotate(t_dvec *vector, double angle)
{
	t_dvec old;

	old = *vector;
	vector->x = old.x * cos(angle * TPI) - old.y * sin(angle * TPI);
	vector->y = old.x * sin(angle * TPI) + old.y * cos(angle * TPI);
}

void rotate_2(t_dvec *vector, t_dvec *vector_2, double angle)
{
	t_dvec old;
	t_dvec old_2;

	old = *vector;
	old_2 = *vector_2;
	vector->x = old.x * cos(angle * TPI) - old.y * sin(angle * TPI);
	vector->y = old.x * sin(angle * TPI) + old.y * cos(angle * TPI);
	vector_2->x = old_2.x * cos(angle * TPI) - old_2.y * sin(angle * TPI);
	vector_2->y = old_2.x * sin(angle * TPI) + old_2.y * cos(angle * TPI);
}