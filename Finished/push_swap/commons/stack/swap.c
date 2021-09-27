/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 13:32:22 by mlabouri          #+#    #+#             */
/*   Updated: 2021/03/18 13:32:22 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/commons.h"

static char	swap(t_stack stack)
{
	int	temp;

	if (stack.len <= 1)
		return (0);
	temp = stack.arr[0];
	stack.arr[0] = stack.arr[1];
	stack.arr[1] = temp;
	return (0);
}

char		swap_a(t_stack *a, t_stack *b)
{
	(void)b;
	return (swap(*a));
}

char		swap_b(t_stack *a, t_stack *b)
{
	(void)a;
	return (swap(*b));
}

char		swap_s(t_stack *a, t_stack *b)
{
	return ((char)(swap(*a) || swap(*b)));
}
