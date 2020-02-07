/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_length_tree.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 15:50:51 by mlabouri          #+#    #+#             */
/*   Updated: 2020/02/07 10:16:09 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/trees.h"

int length_int(char conv, unsigned long long int arg)
{
	if (ft_cinset(conv, "di"))
		return (ft_nbr_len((int) arg));
	//if (ft_cinset(conv, "Xx"))
	//	return (ft_nbrbase_len((int)arg, HEXX));
	if (conv == 'u')
		return (ft_unbr_len((unsigned int)arg));
}

int length_string(char conv, unsigned long long int arg)
{
	return (ft_strlen((char *)arg));
}

int length_char(char conv, unsigned long long int arg)
{
	return (1);
}