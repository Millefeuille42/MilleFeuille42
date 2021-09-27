/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 13:32:17 by mlabouri          #+#    #+#             */
/*   Updated: 2021/03/18 13:32:17 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/commons.h"

static char	rotate(t_stack *stack)
{
	int		*temp;
	t_stack	temp_stack;

	if (stack->len <= 1)
		return (0);
	temp = malloc(sizeof(int) * (stack->len));
	if (temp == NULL)
		return (1);
	temp_stack = stack_copy(stack, temp, 1, 0);
	temp_stack.arr[stack->len - 1] = stack->arr[0];
	if (stack->arr)
	{
		free(stack->arr);
		stack->arr = NULL;
	}
	*stack = temp_stack;
	return (0);
}

char		rotate_a(t_stack *a, t_stack *b)
{
	(void)b;
	return (rotate(a));
}

char		rotate_b(t_stack *a, t_stack *b)
{
	(void)a;
	return (rotate(b));
}

char		rotate_r(t_stack *a, t_stack *b)
{
	return ((char)(rotate(a) || rotate(b)));
}
