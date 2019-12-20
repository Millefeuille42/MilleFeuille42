/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convs_disp_tree.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 16:14:08 by mlabouri          #+#    #+#             */
/*   Updated: 2019/12/20 17:17:19 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trees.h"

// diuxX
// c
// s
// p
// %

void	disp_int(char conv, unsigned long long int arg)
{

}

void	disp_char(char conv, unsigned long long int arg)
{
	ft_putchar_fd((char)arg, 1);
}

void	disp_string(char conv, unsigned long long int arg)
{
	ft_putstr_fd((char *)arg, 1);
}

void	disp_pointer(char conv, unsigned long long int arg)
{
	return ;
}