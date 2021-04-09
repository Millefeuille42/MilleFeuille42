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
	insertion_sort(&stack_a, &stack_b);
	if (stack_a.arr)
		free(stack_a.arr);
	if (stack_b.arr)
		free(stack_b.arr);
	return (0);
}
