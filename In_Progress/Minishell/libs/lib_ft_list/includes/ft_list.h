/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:32:33 by dboyer            #+#    #+#             */
/*   Updated: 2020/05/13 10:04:08 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef FT_LIST_H
#	define FT_LIST_H
#	include <stdlib.h>
#	include <unistd.h>
#	include <stdarg.h>
#	include <stdio.h>

typedef struct			s_element
{
	void				*content;
	int					index;
	struct s_element	*previous;
	struct s_element	*next;
}						t_element;

typedef struct			s_list
{
	int					size;
	struct s_element	*first;
	struct s_element	*last;

	void				(*append)(struct s_list*, void*);
	void				(*clear)(struct s_list*);
	void				(*remove)(struct s_list*, t_element*);
	void				(*iter)(t_element*, void (*f)(t_element*));
	void				(*insert_before)(struct s_list*, t_element*, void *);
	struct s_list		(*concat)(struct s_list*, struct s_list*);
	struct s_list		(*copy)(struct s_list*);
	struct s_list		(*map)(struct s_list*, void *(*f)(t_element*));

	t_element			*(*get)(struct s_list*, int);
	t_element			*(*search)(t_element*, void *,\
						int (*f)(t_element *, void *));
}						t_list;

void					ft_add_back(t_list *list, void *content);
void					ft_del(t_list *list, t_element *element);
void					ft_clear(t_list *list) __attribute__((hot));
void					ft_list_iter(t_element *element, \
						void (*f)(t_element *element));
void					ft_insert_before(t_list *list,\
						t_element *element, void *content);

t_element				*ft_search(t_element *element, void *content,\
						int (*f)(t_element *element, void *content));
t_element				*ft_new_element(void *content);
t_element				*ft_get_list_element(t_list *list, int index);

t_list					ft_list(void);
t_list					ft_concat(t_list *list1, t_list *list2);
t_list					ft_list_copy(t_list *list);

#	endif
