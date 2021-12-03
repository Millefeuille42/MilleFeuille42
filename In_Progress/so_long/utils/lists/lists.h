/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:34:30 by mlabouri          #+#    #+#             */
/*   Updated: 2021/12/03 13:34:30 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Millefeuille on 23/06/2021.
//

#ifndef LISTS_H
# define LISTS_H

# include <stdlib.h>

typedef struct s_element {
	int					index;
	void				*data;
	struct s_element	*next;
	struct s_element	*prev;
}				t_element;

typedef struct s_list {
	int					size;
	struct s_element	*start;
	struct s_element	*end;
}						t_list;

t_list		new_list(void *data);
int			list_iter(t_list *list, int (*f)(t_element*));
void		list_iter_free(t_list *list);
int			list_prepend(t_list *list, void *data);
int			list_append(t_list *list, void *data);

t_element	*new_element(int index, void *data);
int			element_index_up_shift(t_element *element);

int			ret_error(char *msg, int err);

#endif
