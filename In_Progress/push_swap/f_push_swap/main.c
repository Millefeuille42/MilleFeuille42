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

#include "../commons/includes/commons.h"

static int	get_top(t_stack *a)
{
	int	top;
	int	i;

	top = a->arr[0];
	i = 0;
	while (i < a->len)
	{
		if (a->arr[i] < top)
			top = a->arr[i];
		i++;
	}
	return (top);
}

static void	put_back_to_a(t_stack *a, t_stack *b)
{
	while (b->len > 0)
	{
		printf("pa\n");
		push_a(a, b);
	}
}

static void	sort_loop(t_stack *a, t_stack *b)
{
	int	top;

	top = get_top(a);
	while (a->arr[0] != top)
	{
		if (a->arr[1] == top)
		{
			printf("sa\n");
			swap_a(a, b);
		}
		else if (a->arr[a->len - 1] == top)
		{
			printf("rra\n");
			r_rotate_a(a, b);
		}
		else
		{
			printf("ra\n");
			rotate_a(a, b);
		}
	}
}

void		noob_sort(t_stack *a, t_stack *b)
{
	while (a->len > 1)
	{
		if (!check_stacks(a, b, 1))
			break ;
		sort_loop(a, b);
		printf("pb\n");
		push_b(a, b);
	}
	put_back_to_a(a, b);
}

int			main(int argc, char *argv[])
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
	noob_sort(&stack_a, &stack_b);
	if (stack_a.arr)
		free(stack_a.arr);
	if (stack_b.arr)
		free(stack_b.arr);
	return (0);
}
