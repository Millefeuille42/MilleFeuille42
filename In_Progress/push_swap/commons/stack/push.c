/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 13:32:12 by mlabouri          #+#    #+#             */
/*   Updated: 2021/03/18 13:32:12 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/commons.h"

static char	push(t_stack *stack1, t_stack *stack2)
{
	int	val;

	if (stack2->len <= 0)
		return (0);
	if (stack_pop(stack2, &val))
		return (1);
	if (stack_push(stack1, val))
		return (1);
	return (0);
}

char		push_a(t_stack *a, t_stack *b)
{
	return (push(a, b));
}

char		push_b(t_stack *a, t_stack *b)
{
	return (push(b, a));
}
