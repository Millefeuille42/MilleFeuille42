/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_list_element.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:43:28 by dboyer            #+#    #+#             */
/*   Updated: 2020/05/12 16:12:23 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_element	*ft_get_list_element(t_list *list, int index)
{
	t_element	*next;

	if (index < list->size)
	{
		next = list->first;
		while (next && next->index != index)
			next = next->next;
		return (next);
	}
	return (NULL);
}
