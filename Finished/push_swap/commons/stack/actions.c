/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 13:32:10 by mlabouri          #+#    #+#             */
/*   Updated: 2021/03/18 13:32:10 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/commons.h"

t_stack		stack_copy(t_stack *stack, int *arr, int start_off, int i_off)
{
	int	i;

	i = start_off;
	while (i < stack->len)
	{
		arr[i - start_off + i_off] = stack->arr[i];
		i++;
	}
	return ((t_stack){.arr = arr, .len = stack->len});
}

char		stack_push(t_stack *stack, int val)
{
	int		*temp;
	t_stack	temp_stack;

	temp = malloc(sizeof(int) * (stack->len + 1));
	if (temp == NULL)
		return (1);
	temp_stack = stack_copy(stack, temp, 0, 1);
	temp_stack.arr[0] = val;
	if (stack->arr)
	{
		free(stack->arr);
		stack->arr = NULL;
	}
	temp_stack.len += 1;
	*stack = temp_stack;
	return (0);
}

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

char		select_action(t_stack *a, t_stack *b, char *action)
{
	int			i;
	static char	*action_list[11] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb",
									"rr", "rra", "rrb", "rrr"};

	i = 0;
	if (ft_strlen(action) <= 1)
		return (1);
	while (i < 11)
	{
		if (!ft_strncmp(action, action_list[i], ft_strlen(action)))
			return (do_action(a, b, i));
		i++;
	}
	return (1);
}
