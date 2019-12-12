/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convs_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 13:08:28 by mlabouri          #+#    #+#             */
/*   Updated: 2019/12/12 15:31:16 by mlabouri         ###   ########.fr       */
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
	return ('c');
}

char	val_string(const char *s, size_t i, unsigned long long int arg)
{
	ft_putstr_fd((char *)arg, 1);
	return ('s');
}

char	val_pointer(const char *s, size_t i, unsigned long long int arg)
{
	//if (ok) {return ('p' + 100)}
	//else {return 'p'}
	return (2);
}