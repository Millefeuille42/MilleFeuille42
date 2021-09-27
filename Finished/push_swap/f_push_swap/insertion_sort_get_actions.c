/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort_get_actions.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 15:46:57 by mlabouri          #+#    #+#             */
/*   Updated: 2021/04/12 15:46:57 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	i_s_select_reverse(t_stack *a, t_stack *b, t_b_move_set *move_set)
{
	if (move_set->moves > 0)
	{
		printf("rrb\n");
		r_rotate_b(a, b);
		move_set->moves--;
	}
	if (move_set->a_index > 0)
	{
		printf("ra\n");
		rotate_a(a, b);
		move_set->a_index--;
	}
}

static void	i_s_select(t_stack *a, t_stack *b, t_b_move_set *move_set)
{
	if (move_set->moves > 0 && move_set->a_index > 0)
	{
		printf("rr\n");
		rotate_r(a, b);
		move_set->a_index--;
		move_set->moves--;
	}
	else
	{
		if (move_set->a_index > 0)
		{
			printf("ra\n");
			rotate_a(a, b);
			move_set->a_index--;
		}
		if (move_set->moves > 0)
		{
			printf("rb\n");
			rotate_b(a, b);
			move_set->moves--;
		}
	}
}

void		i_s_select_actions(t_stack *a, t_stack *b, t_b_move_set *move_set)
{
	if (move_set->do_reverse)
		i_s_select_reverse(a, b, move_set);
	else
		i_s_select(a, b, move_set);
}
