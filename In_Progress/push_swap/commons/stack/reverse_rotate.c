/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 13:32:15 by mlabouri          #+#    #+#             */
/*   Updated: 2021/03/18 13:32:15 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/commons.h"

static char	r_rotate(t_stack *stack)
{
	int		i;
	int		*temp;

	if (stack->len <= 1)
		return (0);
	temp = malloc(sizeof(int) * (stack->len));
	if (temp == NULL)
		return (1);
	i = 1;
	while (i < stack->len)
	{
		temp[i] = stack->arr[i - 1];
		i++;
	}
	temp[0] = stack->arr[stack->len - 1];
	if (stack->arr)
	{
		free(stack->arr);
		stack->arr = NULL;
	}
	stack->arr = temp;
	return (0);
}

char		r_rotate_a(t_stack *a, t_stack *b)
{
	(void)b;
	return (r_rotate(a));
}

char		r_rotate_b(t_stack *a, t_stack *b)
{
	(void)a;
	return (r_rotate(b));
}

char		r_rotate_r(t_stack *a, t_stack *b)
{
	return ((char)(r_rotate(a) || r_rotate(b)));
}
