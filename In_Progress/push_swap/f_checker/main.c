#include "../commons/includes/commons.h"

char	input_loop(t_stack *stack_a, t_stack *stack_b)
{
	char	*stdin_buffer;

	while (get_next_line(0, &stdin_buffer) && *stdin_buffer)
	{
		if (select_action(stack_a, stack_b, stdin_buffer))
		{
			safe_free((void **) &stdin_buffer);
			safe_free((void **) &(stack_a->arr));
			safe_free((void **) &(stack_b->arr));
			return (1);
		}
		safe_free((void **) &stdin_buffer);
	}
	safe_free((void **) &stdin_buffer);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_stack	stack_a;
	t_stack	stack_b;

	stack_a = (t_stack){};
	stack_b = (t_stack){};
	if (generate_stacks(&stack_a, &stack_b, argc, argv))
		return (print_error(1, "Error"));
	if (check_duplicates(&stack_a))
	{
		free(stack_a.arr);
		free(stack_b.arr);
		return (print_error(1, "Error"));
	}
	if (input_loop(&stack_a, &stack_b))
		return (print_error(1, "Error"));
	if (check_stacks(&stack_a, &stack_b, 0))
		return (print_error(2, "KO"));
	printf("OK\n");
	if (stack_a.arr)
		free(stack_a.arr);
	if (stack_b.arr)
		free(stack_b.arr);
	return (0);
}
