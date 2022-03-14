/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:34:25 by mlabouri          #+#    #+#             */
/*   Updated: 2021/12/03 13:34:25 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Millefeuille on 23/06/2021.
//

#include "lists.h"

void	list_iter_free(t_list *list)
{
	t_element	*cur;
	t_element	*temp;

	cur = list->start;
	while (cur)
	{
		temp = cur->next;
		free(cur);
		cur = temp;
	}
}

int	list_iter(t_list *list, int (*f)(t_element*))
{
	t_element	*cur;
	int			err;

	cur = list->start;
	while (cur)
	{
		err = f(cur);
		if (err)
			return (err);
		cur = cur->next;
	}
	return (0);
}

int	list_prepend(t_list *list, void *data)
{
	t_element	*el;

	el = new_element(0, data);
	if (!el)
		exit(ret_error("Malloc error\n", 2));
	el->next = list->start;
	list_iter(list, element_index_up_shift);
	list->start->prev = el;
	list->start = el;
	list->size++;
	return (0);
}

int	list_append(t_list *list, void *data)
{
	t_element	*el;

	el = new_element(list->end->index + 1, data);
	if (!el)
		exit(ret_error("Malloc error\n", 2));
	el->prev = list->end;
	list->end->next = el;
	list->end = el;
	list->size++;
	return (0);
}

t_list	new_list(void *data)
{
	t_list	ret;

	ret.size = 1;
	ret.start = new_element(0, data);
	if (!ret.start)
		exit(ret_error("Malloc error\n", 2));
	ret.end = ret.start;
	return (ret);
}
