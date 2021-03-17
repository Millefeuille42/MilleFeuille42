//
// Created by millefeuille on 17/03/2021.
//

#include "../includes/commons.h"

static char	do_action(t_stack *a, t_stack *b, int action_num)
{
	t_actions	actions;

	actions[0] = &swap_a;
	actions[1] = &swap_b;
	actions[2] = &swap_s;
	actions[3] = &push_a;
	actions[4] = &push_b;
	actions[5] = &rotate_a;
	actions[6] = &rotate_b;
	actions[7] = &rotate_r;
	actions[8] = &r_rotate_a;
	actions[9] = &r_rotate_b;
	actions[10] = &r_rotate_r;
	return (actions[action_num](a, b));
}

char	select_action(t_stack *a, t_stack *b, char *action)
{
	int			i;
	static char	*action_list[11] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb",
									   "rr", "rra", "rrb", "rrr"};

	i = 0;
	while (i < 11)
	{
		if (!ft_strncmp(action, action_list[i], ft_strlen(action_list[i])))
			return (do_action(a, b, i));
		i++;
	}
	return (1);
}
