#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../commons/includes/commons.h"

typedef struct	s_b_move_set
{
	char		do_reverse;
	int			moves;
	int			a_index;
	int			total_moves;
}				t_b_move_set;

void			put_back_to_a(t_stack *a, t_stack *b);
void			do_action_speak(t_stack *a, t_stack *b, char *act, t_action f);
void			insertion_sort(t_stack *a, t_stack *b);
char			should_reverse(t_stack *a, int val);
char			selection_sort(t_stack *a, t_stack *b);
int				get_highest(t_stack *b);
void			i_s_select_actions(t_stack *a, t_stack *b, t_b_move_set *m_s);

#endif
