/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_disp_tree.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 16:14:08 by mlabouri          #+#    #+#             */
/*   Updated: 2020/01/29 15:50:19 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trees.h"

void	disp_minus(int bin, unsigned long long int arg, char conv)
{

}

void	disp_zero(int bin, unsigned long long int arg, char conv)
{
	int length;

	length = func[conv];
	while (length != 0)
	{
		ft_putchar_fd('0', 1);
		length--;
	}
}

void	disp_dot(int bin, unsigned long long int arg, char conv)
{

}

void	disp_42(int bin, unsigned long long int arg, char conv)
{

}