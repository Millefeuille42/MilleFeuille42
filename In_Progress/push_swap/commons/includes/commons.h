/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commons.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 13:32:08 by mlabouri          #+#    #+#             */
/*   Updated: 2021/03/18 13:32:08 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMONS_H
# define COMMONS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_stack {
	int			*arr;
	int			len;
}				t_stack;

typedef char	(*t_actions[11])(t_stack *a, t_stack *b);
typedef char	(*t_action)(t_stack *a, t_stack *b);

void			safe_free(void **ptr);

char			print_error(char err_code, char *message);

int				ft_isdigit(int c);
long			ft_atoi(const char *str);
int				ft_is_string_digit(char *str);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				get_next_line(int fd, char **line);

char			*ft_strchr(const char *s, int c);
char			*ft_substr(char *s, unsigned int start, size_t len);
char			*ft_strjoin(char *s1, char *s2);

size_t			ft_strlen(const char *str);

char			generate_stacks(t_stack *a, t_stack *b, int argc, char *argv[]);
char			check_stacks(t_stack *stack_a, t_stack *stack_b, char only_a);
char			check_duplicates(t_stack *a);

t_stack			stack_copy(t_stack *stack, int *arr, int start_off, int i_off);

char			stack_push(t_stack *stack, int val);
char			stack_pop(t_stack *stack, int *val);

char			push_a(t_stack *a, t_stack *b);
char			push_b(t_stack *a, t_stack *b);

char			swap_a(t_stack *a, t_stack *b);
char			swap_b(t_stack *a, t_stack *b);
char			swap_s(t_stack *a, t_stack *b);

char			rotate_a(t_stack *a, t_stack *b);
char			rotate_b(t_stack *a, t_stack *b);
char			rotate_r(t_stack *a, t_stack *b);

char			r_rotate_a(t_stack *a, t_stack *b);
char			r_rotate_b(t_stack *a, t_stack *b);
char			r_rotate_r(t_stack *a, t_stack *b);

char			select_action(t_stack *a, t_stack *b, char *action);

#endif
