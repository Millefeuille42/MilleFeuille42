/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 13:32:20 by mlabouri          #+#    #+#             */
/*   Updated: 2021/03/18 13:32:20 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/commons.h"

char		stack_pop(t_stack *stack, int *val)
{
	int		*temp;
	t_stack	temp_stack;

	temp = malloc(sizeof(int) * (stack->len - 1));
	if (temp == NULL)
		return (1);
	temp_stack = stack_copy(stack, temp, 1, 0);
	*val = stack->arr[0];
	if (stack->arr)
	{
		free(stack->arr);
		stack->arr = NULL;
	}
	temp_stack.len -= 1;
	*stack = temp_stack;
	return (0);
}

char		check_stacks(t_stack *stack_a, t_stack *stack_b, char only_a)
{
	int	i;

	if (stack_b->len && !only_a)
		return (1);
	i = 1;
	while (i < stack_a->len)
	{
		if (stack_a->arr[i] < stack_a->arr[i - 1])
			return (1);
		i++;
	}
	return (0);
}

char		check_duplicates(t_stack *a)
{
	int	i;
	int	i2;

	i = 0;
	while (i < a->len)
	{
		i2 = 0;
		while (i2 < a->len)
		{
			if (a->arr[i2] == a->arr[i] && i != i2)
				return (1);
			i2++;
		}
		i++;
	}
	return (0);
}

static char	check_im(char *arg, int *val)
{
	long	ret;

	ret = ft_atoi(arg);
	if (ret > 2147483647)
		return (1);
	*val = (int)ret;
	return (0);
}

char		generate_stacks(t_stack *a, t_stack *b, int argc, char *argv[])
{
	int	i;

	i = 1;
	if (argc <= 1)
		return (1);
	a->arr = malloc(sizeof(int) * argc);
	if (!a->arr)
		return (1);
	b->arr = malloc(sizeof(int) * 0);
	if (!b->arr)
		return (1);
	while (i < argc)
	{
		if (!argv || !argv[i] || !ft_is_string_digit(argv[i]) ||
			check_im(argv[i], &a->arr[i - 1]))
		{
			free(a->arr);
			free(b->arr);
			return (1);
		}
		i++;
	}
	a->len = argc - 1;
	return (0);
}
