/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_length_tree.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 15:50:51 by mlabouri          #+#    #+#             */
/*   Updated: 2020/02/13 17:59:23 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/trees.h"

int length_int(char conv, unsigned long long int arg, struct s_f *bin)
{
	int length;

	if (ft_cinset(conv, "di"))
		length = ft_nbr_len((int)arg);
	else if (ft_cinset(conv, "Xx"))
		length = ft_nbrbase_len((unsigned long)arg, HEX);
	else
		length = ft_unbr_len((unsigned int)arg);
	if(bin->dotc)
		bin->dotc = length;
	if (bin->dotc && bin->dot != 0 && arg != 0)
		length = 0;
	return (length);
}

int		length_char(char conv, unsigned long long int arg, struct s_f *bin)
{
	conv = 0;
	arg = 0;
	bin = bin;
	return (1);
}

int		length_string(char conv, unsigned long long int arg, struct s_f *bin)
{
	int length;

	length = ft_strlen((char *)arg);
	if(bin->dotc)
		bin->dotc = length;
	if (bin->dotc && bin->dot < length)
		length = bin->dot;
	return (length);
}

int		length_pointer(char conv, unsigned long long int arg, struct s_f *bin)
{
	int i;

	conv = 0;
	i = 2;
	return (i + length_int('x', arg, bin));
}