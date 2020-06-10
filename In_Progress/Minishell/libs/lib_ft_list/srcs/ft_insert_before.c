/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert_before.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 12:29:19 by dboyer            #+#    #+#             */
/*   Updated: 2020/05/13 10:05:42 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

static inline void	correct_index(t_element *element)
{
	element->index++;
}

void				ft_insert_before(t_list *list, t_element *element,\
									void *content)
{
	t_element *new_elem;

	if (element)
	{
		new_elem = ft_new_element(content);
		if (element->index == 0)
		{
			new_elem->index = element->index;
			new_elem->next = element;
			element->previous = new_elem;
			list->first = new_elem;
		}
		else
		{
			new_elem->previous = element->previous;
			new_elem->next = element;
			new_elem->index = element->index;
			element->previous->next = new_elem;
			element->previous = new_elem;
		}
		list->iter(new_elem->next, correct_index);
		list->size++;
	}
}
