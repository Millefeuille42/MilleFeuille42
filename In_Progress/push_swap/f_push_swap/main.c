//
// Created by millefeuille on 17/03/2021.
//

#include "../commons/includes/commons.h"



int	main(int argc, char *argv[]) {
	t_stack	stack_a;
	t_stack	stack_b;

	stack_a = (t_stack){};
	stack_b = (t_stack){};
	if (generate_stacks(&stack_a, &stack_b, argc, argv))
		print_error(1, "Error");

	if (stack_a.arr)
		free(stack_a.arr);
	if (stack_b.arr)
		free(stack_b.arr);
	return (0);
}

//	if (check_stacks(&stack_a, &stack_b))
//		print_error(2, "KO");