/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convs_disp_tree.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 16:14:08 by mlabouri          #+#    #+#             */
/*   Updated: 2019/12/24 10:50:42 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trees.h"

void	disp_minus(int conv, unsigned long long int arg)
{

}

void	disp_zero(int conv, unsigned long long int arg)
{
	int length;

	length = 1;
	while ((int)arg > 10)
	{
		arg = (int)arg / 10;
		length++;
	}
	length = conv - length;
	while (length != 0)
	{
		ft_putchar_fd('0', 1);
		length--;
	}
}

void	disp_dot(int conv, unsigned long long int arg)
{

}

void	disp_42(int conv, unsigned long long int arg)
{

}