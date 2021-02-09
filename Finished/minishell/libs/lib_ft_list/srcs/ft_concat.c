/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 13:42:55 by dboyer            #+#    #+#             */
/*   Updated: 2020/06/23 17:00:30 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

static	void		append(t_list *list1, t_list *list2)
{
	t_element *next;

	next = list2->first;
	while (next)
	{
		ft_add_back(list1, next->content);
		next = next->next;
	}
}

t_list				ft_concat(t_list *list1, t_list *list2)
{
	t_list		new;

	new = ft_list();
	append(&new, list1);
	append(&new, list2);
	return (new);
}
