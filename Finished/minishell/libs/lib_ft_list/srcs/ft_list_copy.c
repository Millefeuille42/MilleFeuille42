/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_copy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 15:41:38 by dboyer            #+#    #+#             */
/*   Updated: 2020/05/12 16:12:23 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	ft_list_copy(t_list *list)
{
	t_list		new_list;
	t_element	*next;

	new_list = ft_list();
	next = list->first;
	while (next)
	{
		new_list.append(&new_list, next->content);
		next = next->next;
	}
	return (new_list);
}
