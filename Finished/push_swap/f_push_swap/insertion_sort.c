/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 15:46:55 by mlabouri          #+#    #+#             */
/*   Updated: 2021/04/12 15:46:55 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				index_traversal(t_stack *b, int b_i, t_b_move_set *b_move_set)
{
	if (b_move_set->do_reverse)
		b_i--;
	else
		b_i++;
	b_i %= b->len;
	if (b_i < 0)
		b_i = b->len - 1;
	b_move_set->moves++;
	return (b_i);
}

t_b_move_set	get_index_value(t_stack *a, t_stack *b, int offset, int a_i)
{
	int				b_i;
	int				dest;
	t_b_move_set	b_move_set;

	b_i = offset;
	while (a->arr[a_i] < b->arr[b_i])
	{
		b_i++;
		b_i %= b->len;
	}
	dest = b->arr[b_i];
	b_move_set.do_reverse = should_reverse(b, dest);
	b_move_set.moves = 0;
	b_i = 0;
	while (b->arr[b_i] != dest)
		b_i = index_traversal(b, b_i, &b_move_set);
	b_move_set.a_index = a_i;
	b_move_set.total_moves = b_move_set.moves;
	b_move_set.total_moves += b_move_set.a_index;
	return (b_move_set);
}

t_b_move_set	get_best_a_index(t_stack *a, t_stack *b, int offset)
{
	int				a_i;
	t_b_move_set	b_move_set;
	t_b_move_set	best_b_move_set;

	best_b_move_set.total_moves = -1;
	a_i = 0;
	while (a_i < a->len)
	{
		b_move_set = get_index_value(a, b, offset, a_i);
		if (b_move_set.total_moves < best_b_move_set.total_moves
		|| best_b_move_set.total_moves == -1)
			best_b_move_set = b_move_set;
		a_i++;
	}
	return (best_b_move_set);
}

int				move_b_index(t_stack *a, t_stack *b, int offset)
{
	int				i;
	int				highest;
	int				lowest_index;
	t_b_move_set	move_set;

	move_set = get_best_a_index(a, b, offset);
	while (move_set.moves > 0 || move_set.a_index > 0)
		i_s_select_actions(a, b, &move_set);
	printf("pb\n");
	push_b(a, b);
	i = 0;
	highest = b->arr[0];
	lowest_index = 0;
	while (i < b->len)
	{
		if (b->arr[i] > highest)
		{
			highest = b->arr[i];
			lowest_index = i;
		}
		i++;
	}
	return (lowest_index);
}

void			insertion_sort(t_stack *a, t_stack *b)
{
	int		offset;
	char	do_reverse;
	char	do_swap;

	offset = 0;
	do_swap = selection_sort(a, b);
	printf("pb\n");
	push_b(a, b);
	if (do_swap == 1)
	{
		printf("sb\n");
		swap_b(a, b);
	}
	while (a->len > 0)
		offset = move_b_index(a, b, offset);
	put_back_to_a(a, b);
	do_reverse = should_reverse(a, get_highest(b));
	while (check_stacks(a, b, 0))
	{
		if (do_reverse)
			do_action_speak(a, b, "rra\n", r_rotate_a);
		else
			do_action_speak(a, b, "ra\n", rotate_a);
	}
}
