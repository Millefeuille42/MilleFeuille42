/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 16:54:36 by mlabouri          #+#    #+#             */
/*   Updated: 2019/12/20 14:35:59 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define FLAGS "-0.*"
# define CONVS "cspdiuxX"
# define INTS "diuxX"
# define ALL "cspdiuxX%-0.*"
# define HEXX "123456789ABCDEF"
# define HEX "123456789abcdef"

# include <stdarg.h>
# include <string.h>
# include <stdio.h> //remove
# include <unistd.h>

size_t		ft_args(char *s, size_t i, unsigned long long int arg);
void		ft_disp(char bin[], unsigned long long arg, char conv);
size_t		ft_putstr_fd_c(char *s, int fd, char c, size_t i);
void		ft_putstr_fd(char *s, int fd);
void		ft_putchar_fd(char c, int f);
void		ft_putnbr_fd(int n, int fd);
char		ft_cinset(char c, const char *set);
size_t		ft_strlen(const char *str);
#endif