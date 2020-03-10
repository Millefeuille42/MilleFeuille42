/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trees.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 10:30:08 by mlabouri          #+#    #+#             */
/*   Updated: 2020/03/10 14:31:15 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREES_H
# define TREES_H

# include "ft_printf.h"

int		val_minus(const char *s, size_t i, va_list *args);
int		val_zero(const char *s, size_t i, va_list *args);
int		val_dot(const char *s, size_t i, va_list *args, int *dotc);
int		val_pad(const char *s, size_t i, va_list *args);

void	disp_int(char conv, struct s_c arg);
void	disp_char(struct s_c arg);
void	disp_string(struct s_c arg);
void	disp_pointer(struct s_c arg);

int		disp_minus(struct s_f *bin, struct s_c arg, char conv);
int		disp_zero(struct s_f *bin, struct s_c arg, char conv);
int		disp_dot(struct s_f *bin, struct s_c arg, char conv);
int		disp_pad(struct s_f *bin, struct s_c arg, char conv);

int		length_int(char c, struct s_c arg, struct s_f *bin);
int		length_char(char c, struct s_c arg, struct s_f *bin);
int		length_string(char c, struct s_c arg, struct s_f *bin);
int		length_pointer(char c, struct s_c arg, struct s_f *bin);

#endif
