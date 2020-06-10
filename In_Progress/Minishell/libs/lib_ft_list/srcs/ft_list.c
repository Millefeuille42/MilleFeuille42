/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 12:30:29 by dboyer            #+#    #+#             */
/*   Updated: 2020/05/12 16:16:29 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list		ft_list(void)
{
	t_list new;

	new.size = 0;
	new.append = ft_add_back;
	new.clear = ft_clear;
	new.concat = ft_concat;
	new.remove = ft_del;
	new.iter = ft_list_iter;
	new.get = ft_get_list_element;
	new.copy = ft_list_copy;
	new.search = ft_search;
	new.insert_before = ft_insert_before;
	return (new);
}
