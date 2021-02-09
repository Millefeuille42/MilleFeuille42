/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 20:45:45 by dboyer            #+#    #+#             */
/*   Updated: 2020/09/29 12:29:33 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_element	*ft_search(t_element *element, void *content,\
		int (*f)(t_element *element, void *content))
{
	if (element && !f(element, content))
		return (ft_search(element->next, content, f));
	else if (!element)
		return (NULL);
	return (element);
}
