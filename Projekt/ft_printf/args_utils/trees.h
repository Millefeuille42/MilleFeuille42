/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trees.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 12:55:35 by mlabouri          #+#    #+#             */
/*   Updated: 2019/12/10 13:31:13 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef TREES_H
# define TREES_H

# include "../ft_printf.h"

char	val_minus(const char *s, size_t i);
char	val_zero(const char *s, size_t i);
char	val_dot(const char *s, size_t i);
char	val_42(const char *s, size_t i);
char	val_int(const char *s, size_t i, void **arg);
char	val_char(const char *s, size_t i, void **arg);
char	val_string(const char *s, size_t i, void **arg);
char	val_pointer(const char *s, size_t i, void **arg);
char	val_percent(const char *s, size_t i, void **arg);

#endif
