/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convs_val_tree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 16:13:50 by mlabouri          #+#    #+#             */
/*   Updated: 2019/12/12 16:13:59 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trees.h"

// diuxX
// c
// s
// p
// %

char	val_int(const char *s, size_t i, unsigned long long int arg)
{
	//if (ok) {return ('conv' + 100)}
	//else {return 'conv'}
	return (2);
}

char	val_char(const char *s, size_t i, unsigned long long int arg)
{
	ft_putchar_fd((char)arg, 1);
	return (0);
}

char	val_string(const char *s, size_t i, unsigned long long int arg)
{
	ft_putstr_fd((char *)arg, 1);
	return (1);
}

char	val_pointer(const char *s, size_t i, unsigned long long int arg)
{
	//if (ok) {return ('p' + 100)}
	//else {return 'p'}
	return (2);
}