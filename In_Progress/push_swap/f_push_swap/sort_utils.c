#include "push_swap.h"

int		get_highest(t_stack *b)
{
	int	i;
	int	highest;

	i = 0;
	highest = b->arr[0];
	while (i < b->len)
	{
		if (b->arr[i] < highest)
			highest = b->arr[i];
		i++;
	}
	return (highest);
}

void	put_back_to_a(t_stack *a, t_stack *b)
{
	while (b->len > 0)
		do_action_speak(a, b, "pa\n", push_a);
}

char	should_reverse(t_stack *a, int val)
{
	int i;
	int i2;
	int i3;

	i = 0;
	while (i < a->len && a->arr[i] != val)
		i++;
	i2 = a->len - 1;
	i3 = 1;
	while (i2 >= 0 && a->arr[i2] != val)
	{
		i2--;
		i3++;
	}
	return ((char)(i3 < i));
}

void	do_action_speak(t_stack *a, t_stack *b, char *act, t_action f)
{
	printf("%s", act);
	f(a, b);
}
