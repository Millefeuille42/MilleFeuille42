/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trees.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 12:55:35 by mlabouri          #+#    #+#             */
/*   Updated: 2020/02/04 16:04:35 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREES_H
# define TREES_H

# include "ft_printf.h"

int 	val_minus(const char *s, size_t i, va_list *args);
int 	val_zero(const char *s, size_t i, va_list *args);
int 	val_dot(const char *s, size_t i, va_list *args);
int		val_pad(const char *s, size_t i, va_list *args);

void	disp_int(char conv, unsigned long long int arg);
void	disp_char(char conv, unsigned long long int arg);
void	disp_string(char conv, unsigned long long int arg);
void	disp_pointer(char conv, unsigned long long int arg);

void	disp_minus(int bin[], unsigned long long int arg, char conv);
void	disp_zero(int bin[], unsigned long long int arg, char conv);
void	disp_dot(int bin[], unsigned long long int arg, char conv);
void	disp_pad(int bin[], unsigned long long int arg, char conv);

int		length_int(char conv, unsigned long long int arg);
int		length_char(char conv, unsigned long long int arg);
int		length_string(char conv, unsigned long long int arg);


#endif