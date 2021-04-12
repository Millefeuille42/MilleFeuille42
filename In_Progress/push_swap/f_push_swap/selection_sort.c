#include "push_swap.h"

static int	get_lowest_after(t_stack *a, int after)
{
	int	lowest;
	int	i;

	lowest = a->arr[0];
	i = 0;
	while (i < a->len)
	{
		if (a->arr[i] < lowest && a->arr[i] != after)
			lowest = a->arr[i];
		i++;
	}
	return (lowest);
}

int			get_lowest(t_stack *a)
{
	int	lowest;
	int	i;

	lowest = a->arr[0];
	i = 0;
	while (i < a->len)
	{
		if (a->arr[i] < lowest)
			lowest = a->arr[i];
		i++;
	}
	return (lowest);
}

static char	selection_loop(t_stack *a, t_stack *b, int lowest, int next_lowest)
{
	char do_swap;
	char do_reverse;

	do_swap = 0;
	do_reverse = should_reverse(a, lowest);
	while (a->arr[0] != lowest)
	{
		if (a->arr[0] == next_lowest)
		{
			do_action_speak(a, b, "pb\n", push_b);
			do_swap = 1;
		}
		else
		{
			if (do_reverse)
				do_action_speak(a, b, "rra\n", r_rotate_a);
			else
				do_action_speak(a, b, "ra\n", rotate_a);
		}
	}
	return (do_swap);
}

char		selection_sort(t_stack *a, t_stack *b)
{
	int		lowest;
	int		next_lowest;

	lowest = get_lowest(a);
	next_lowest = get_lowest_after(a, lowest);
	return (selection_loop(a, b, lowest, next_lowest));
}
