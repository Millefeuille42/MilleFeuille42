/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_length_tree.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 15:50:51 by mlabouri          #+#    #+#             */
/*   Updated: 2020/01/29 15:59:59 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trees.h"

int length_int(char conv, unsigned long long int arg)
{
	if (ft_cinset(conv, "di"))
		return (ft_nbr_len((int) arg));
	if (ft_cinset(conv, "Xx"))
		return (ft_nbrbase_len((int)arg, HEXX));
}

int length_string(char conv, unsigned long long int arg)
{
	return (ft_strlen((char *)arg));
}