//
// Created by millefeuille on 15/03/2021.
//

#include "../includes/commons.h"

t_stack	stack_copy(t_stack *stack, int *arr, int start_off, int index_offset)
{
	int	i;

	i = start_off;
	while (i < stack->len)
	{
		arr[i - start_off + index_offset] = stack->arr[i];
		i++;
	}
	return ((t_stack){.arr = arr, .len = stack->len});
}

char	stack_push(t_stack *stack, int val)
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

char	stack_pop(t_stack *stack, int *val)
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

char	check_stacks(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	if (stack_b->len)
		return (1);
	i = 1;
	while (i < stack_a->len)
	{
		if (stack_a->arr[i] < stack_a->arr[i - 1])
		{
			return (1);
		}
		i++;
	}
	return (0);
}

void	print_stack(t_stack stack, char name)
{
	int	i;

	printf("STACK: %c -- LEN: %d\n", name, stack.len);
	i = 0;
	while (i < stack.len)
	{
		printf("\tINDEX[%d] -> %d\n", i, stack.arr[i]);
		i++;
	}
}

char	generate_stacks(t_stack *a, t_stack *b, int argc, char *argv[])
{
	int	i;

	i = 1;
	if (argc <= 0)
		return (1);
	a->arr = malloc(sizeof(int) * argc);
	if (!a->arr)
		return (1);
	b->arr = malloc(sizeof(int) * 0);
	if (!b->arr)
		return (1);
	while (i < argc)
	{
		if (!argv || !argv[i] || !ft_is_string_digit(argv[i]))
		{
			free(a->arr);
			return (1);
		}
		a->arr[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	a->len = argc - 1;
	return (0);
}