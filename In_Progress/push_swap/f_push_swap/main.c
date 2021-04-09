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

static int	get_lowest_after(t_stack *a, int after, int *index)
{
	int	lowest;
	int	i;

	lowest = a->arr[0];
	i = 0;
	while (i < a->len)
	{
		if (a->arr[i] < lowest && a->arr[i] != after) {
			lowest = a->arr[i];
			*index = i;
		}
		i++;
	}
	return (lowest);
}

static int	get_lowest(t_stack *a, int *index)
{
	int	lowest;
	int	i;

	lowest = a->arr[0];
	i = 0;
	while (i < a->len)
	{
		if (a->arr[i] < lowest) {
			lowest = a->arr[i];
			*index = i;
		}
		i++;
	}
	return (lowest);
}

static void	put_back_to_a(t_stack *a, t_stack *b)
{
	while (b->len > 0)
	{
		printf("pa\n");
		push_a(a, b);
	}
}

char should_reverse(t_stack *a, int val) {
	int i;
	int i2;
	int i3;

	i = 0;
	while (i < a->len && a->arr[i] != val)
		i++;
	i2 = a->len - 1;
	i3 = 1;
	while (i2 >= 0 && a->arr[i2] != val) {
		i2--;
		i3++;
	}
	return ((char)(i3 < i));
}

static char	sort_loop(t_stack *a, t_stack *b)
{
	int		lowest;
	int		index;
	int		next_index;
	int		next_lowest;
	char do_swap;
	char do_reverse;

	lowest = get_lowest(a, &index);
	next_lowest = get_lowest_after(a, lowest, &next_index);
	do_swap = 0;
	do_reverse = should_reverse(a, lowest);
	while (a->arr[0] != lowest)
	{
		if (a->arr[0] == next_lowest)
		{
			printf("pb\n");
			push_b(a, b);
			do_swap = 1;
		}
		else
		{
			//if (index > (a->len / 3) * 2 || next_index > (a->len / 3) * 2)
			if (do_reverse)
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
	return (do_swap);
}

typedef struct	s_b_move_set {
	char		do_reverse;
	int			moves;
	int			a_index;
	int			total_moves;
}				t_b_move_set;

t_b_move_set	get_best_a_index(t_stack *a, t_stack *b, int offset) {
	int a_i;

	int b_i;
	t_b_move_set b_move_set;
	t_b_move_set best_b_move_set;

	int dest;

	best_b_move_set.total_moves = -1;

	a_i = 0;
	while (a_i < a->len) {
		b_i = offset;
		while (a->arr[a_i] < b->arr[b_i]) {
			b_i++;
			b_i %= b->len;
		}
		dest = b->arr[b_i];
		b_move_set.do_reverse = should_reverse(b, dest);
		b_move_set.moves = 0;
		b_i = 0;
		while (b->arr[b_i] != dest) {
			if (b_move_set.do_reverse)
				b_i--;
			else
				b_i++;
			b_i %= b->len;
			if (b_i < 0) {
				b_i = b->len - 1;
			}
			b_move_set.moves++;
		}
		b_move_set.a_index = a_i;
		b_move_set.total_moves = b_move_set.moves;
		b_move_set.total_moves += b_move_set.a_index;
		if (b_move_set.total_moves < best_b_move_set.total_moves || best_b_move_set.total_moves == -1)
			best_b_move_set = b_move_set;
		a_i++;
	}
	return (best_b_move_set);
}

int		move_b_index(t_stack *a, t_stack *b, int val, int offset) {
	int i;
	int highest;
	int lowest_index;

	t_b_move_set move_set;

	move_set = get_best_a_index(a, b, offset);

	while (move_set.moves > 0 || move_set.a_index > 0) {
		if (move_set.do_reverse)
		{
			if (move_set.moves > 0) {
				printf("rrb\n");
				r_rotate_b(a, b);
				move_set.moves--;
			}
			if (move_set.a_index > 0) {
				printf("ra\n");
				rotate_a(a, b);
				move_set.a_index--;
			}
		}
		else
		{
			if (move_set.moves > 0 && move_set.a_index > 0) {
				printf("rr\n");
				rotate_r(a, b);
				move_set.a_index--;
				move_set.moves--;
			}
			else
			{
				if (move_set.a_index > 0) {
					printf("ra\n");
					rotate_a(a, b);
					move_set.a_index--;
				}
				if (move_set.moves > 0) {
					printf("rb\n");
					rotate_b(a, b);
					move_set.moves--;
				}
			}
		}
	}

	printf("pb\n");
	push_b(a, b);

	i = 0;
	highest = b->arr[0];
	lowest_index = 0;
	while (i < b->len) {
		if (b->arr[i] > highest) {
			highest = b->arr[i];
			lowest_index = i;
		}
		i++;
	}
	return (lowest_index);
}

void		insertion_sort(t_stack *a, t_stack *b) {
	char	do_swap;
	int offset;
	int i;
	int highest;
	char do_reverse;

	offset = 0;
	do_swap = sort_loop(a, b);
	printf("pb\n");
	push_b(a, b);
	if (do_swap == 1)
	{
		printf("sb\n");
		swap_b(a, b);
	}
	while (a->len > 0)
		offset = move_b_index(a, b, a->arr[0], offset);
	put_back_to_a(a, b);

	i = 0;
	highest = b->arr[0];
	while (i < b->len) {
		if (b->arr[i] < highest) {
			highest = b->arr[i];
		}
		i++;
	}
	do_reverse = should_reverse(a, highest);
	while (check_stacks(a, b, 0)) {
		if (do_reverse) {
			printf("rra\n");
			r_rotate_a(a, b);
		}
		else {
			printf("ra\n");
			rotate_a(a, b);
		}
	}
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

	//for (int i = 0; i < b->len; i++)
	//	printf("%-2d. %d\n", i, b->arr[i]);
	insertion_sort(&stack_a, &stack_b);
	//selection_sort(&stack_a, &stack_b);
	if (stack_a.arr)
		free(stack_a.arr);
	if (stack_b.arr)
		free(stack_b.arr);
	return (0);
}