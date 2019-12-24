/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trees.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 12:55:35 by mlabouri          #+#    #+#             */
/*   Updated: 2019/12/14 13:46:58 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREES_H
# define TREES_H

# include "../ft_printf.h"

char	val_minus(const char *s, size_t i);
char	val_zero(const char *s, size_t i);
char	val_dot(const char *s, size_t i);
char	val_42(const char *s, size_t i);
void	disp_int(char conv, unsigned long long int arg);
void	disp_char(char conv, unsigned long long int arg);
void	disp_string(char conv, unsigned long long int arg);
void	disp_pointer(char conv, unsigned long long int arg);

#endif
