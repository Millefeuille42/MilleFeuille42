/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:34:16 by mlabouri          #+#    #+#             */
/*   Updated: 2021/12/03 13:34:16 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Millefeuille on 23/06/2021.
//

#include "lists.h"

int	element_index_up_shift(t_element *element)
{
	element->index++;
	return (0);
}

t_element	*new_element(int index, void *data)
{
	t_element	*ret;

	ret = malloc(sizeof(t_element));
	if (!ret)
		return (NULL);
	*ret = (t_element){.index = index, .data = data};
	return (ret);
}
