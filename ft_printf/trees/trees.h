/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trees.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 12:55:35 by mlabouri          #+#    #+#             */
/*   Updated: 2019/12/12 16:32:46 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREES_H
# define TREES_H

# include "../ft_printf.h"

union	u_display
{
	void	(*putstr)(char *, int);
	void	(*putchar)(char, int);
};

char	val_minus(const char *s, size_t i);
char	val_zero(const char *s, size_t i);
char	val_dot(const char *s, size_t i);
char	val_42(const char *s, size_t i);
char	val_int(const char *s, size_t i, unsigned long long int arg);
char	val_char(const char *s, size_t i, unsigned long long int arg);
char	val_string(const char *s, size_t i, unsigned long long int arg);
char	val_pointer(const char *s, size_t i, unsigned long long int arg);
void	disp_int(char conv, unsigned long long int arg);
void	disp_char(char conv, unsigned long long int arg);
void	disp_string(char conv, unsigned long long int arg);
void	disp_pointer(char conv, unsigned long long int arg);

#endif
