/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_length_tree.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 15:50:51 by mlabouri          #+#    #+#             */
/*   Updated: 2020/02/14 13:49:18 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/trees.h"

int length_int(char conv, struct s_c arg, struct s_f *bin)
{
	int length;

	if (ft_cinset(conv, "di"))
	{
		length = ft_nbr_len((int)arg.diuxX);
		if ((int)arg.diuxX < 0)
			length--;
	}
	else if (ft_cinset(conv, "Xx"))
		length = ft_nbrbase_len((unsigned long)arg.diuxX, HEX);
	else
		length = ft_unbr_len((unsigned long)arg.diuxX);
	if (bin->dotc && bin->dot == 0 && arg.diuxX == 0)
		length = 0;
	else if (bin->dotc && bin->dot >= length)
	{
		bin->dot = bin->dot - length;
		length = bin->dot + length;
	}
	else
		bin->dot = 0;
	return (length);
}

int		length_char(char conv, struct s_c arg, struct s_f *bin)
{
	conv = 0;
	arg = arg;
	bin = bin;
	return (1);
}

int		length_string(char conv, struct s_c arg, struct s_f *bin)
{
	int length;

	length = ft_strlen(arg.s);
	if (bin->dotc && bin->dot < length)
		length = bin->dot;
	else if (bin->dotc)
		bin->dot = length;
	return (length);
}

int		length_pointer(char conv, struct s_c arg, struct s_f *bin)
{
	int i;

	conv = 0;
	i = 2;
	return (i + ft_nbrbase_len(arg.p, HEX));
}