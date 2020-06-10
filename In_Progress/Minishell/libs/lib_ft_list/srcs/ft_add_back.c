/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_back.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 11:27:04 by dboyer            #+#    #+#             */
/*   Updated: 2020/05/12 16:12:23 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void		ft_add_back(t_list *list, void *content)
{
	t_element *new_elem;

	new_elem = ft_new_element(content);
	if (list->size > 0)
	{
		list->size++;
		new_elem->previous = list->last;
		new_elem->index = list->size - 1;
		list->last->next = new_elem;
		list->last = new_elem;
	}
	else
	{
		list->size = 1;
		new_elem->index = 0;
		list->first = new_elem;
		list->last = new_elem;
	}
}
