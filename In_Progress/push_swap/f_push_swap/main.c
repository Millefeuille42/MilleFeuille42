/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 13:47:31 by mlabouri          #+#    #+#             */
/*   Updated: 2021/03/18 13:47:31 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_real_highest(t_stack *b)
{
	int	i;
	int	highest;

	i = 0;
	highest = b->arr[0];
	while (i < b->len)
	{
		if (b->arr[i] > highest)
			highest = b->arr[i];
		i++;
	}
	return (highest);
}

void	three_sort(t_stack *a, t_stack *b)
{
	int	min;
	int max;

	min = get_lowest(a);
	max = get_real_highest(a);
	if (a->arr[0] == min && a->arr[1] == max)
	{
		do_action_speak(a, b, "pb\n", push_b);
		do_action_speak(a, b, "sa\n", swap_a);
		do_action_speak(a, b, "pa\n", push_a);
	}
	else if (a->arr[1] == min && a->arr[2] == max)
		do_action_speak(a, b, "sa\n", swap_a);
	else if (a->arr[2] == min && a->arr[1] == max)
		do_action_speak(a, b, "rra\n", r_rotate_a);
	else if (a->arr[1] == min && a->arr[0] == max)
		do_action_speak(a, b, "ra\n", rotate_a);
	else if (a->arr[2] == min && a->arr[0] == max)
	{
		do_action_speak(a, b, "ra\n", rotate_a);
		do_action_speak(a, b, "sa\n", swap_a);
	}
}

void	five_sort(t_stack *a, t_stack *b)
{
	int lowest;

	lowest = get_lowest(a);
	while (a->arr[0] != lowest)
		do_action_speak(a, b, "ra\n", rotate_a);
	do_action_speak(a, b, "pb\n", push_b);
	lowest = get_lowest(a);
	while (a->arr[0] != lowest)
		do_action_speak(a, b, "ra\n", rotate_a);
	do_action_speak(a, b, "pb\n", push_b);
	three_sort(a, b);
	put_back_to_a(a, b);
}

void	select_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (check_stacks(stack_a, stack_b, 0))
	{
		if (stack_a->len == 2)
			do_action_speak(stack_a, stack_b, "sa\n", swap_a);
		else if (stack_a->len == 3)
			three_sort(stack_a, stack_b);
		else if (stack_a->len == 5)
			five_sort(stack_a, stack_b);
		else
			insertion_sort(stack_a, stack_b);
	}
}

int		main(int argc, char *argv[])
{
	t_stack	stack_a;
	t_stack	stack_b;

	stack_a = (t_stack) {.len = 0, .arr = NULL};
	stack_b = (t_stack) {.len = 0, .arr = NULL};
	if (generate_stacks(&stack_a, &stack_b, argc, argv))
		return (print_error(1, "Error"));
	if (check_duplicates(&stack_a))
	{
		free(stack_a.arr);
		free(stack_b.arr);
		return (print_error(1, "Error"));
	}
	select_sort(&stack_a, &stack_b);
	if (stack_a.arr)
		free(stack_a.arr);
	if (stack_b.arr)
		free(stack_b.arr);
	return (0);
}
