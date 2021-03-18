#include "../includes/commons.h"

static char	swap(t_stack stack)
{
	int	temp;

	if (stack.len <= 1)
		return (1);
	temp = stack.arr[0];
	stack.arr[0] = stack.arr[1];
	stack.arr[1] = temp;
	return (0);
}

char	swap_a(t_stack *a, t_stack *b)
{
	return (swap(*a));
}

char	swap_b(t_stack *a, t_stack *b)
{
	return (swap(*b));
}

char	swap_s(t_stack *a, t_stack *b)
{
	return ((char)(swap(*a) || swap(*b)));
}
