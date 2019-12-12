/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 16:54:36 by mlabouri          #+#    #+#             */
/*   Updated: 2019/12/12 16:31:17 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define FLAGS "-0.*"
# define CONVS "cspdiuxX%"
# define INTS "diuxX"
# define HEXX "123456789ABCDEF"
# define HEX "123456789abcdef"

# include <stdarg.h>
# include <string.h>
# include <stdio.h> //remove
# include <unistd.h>

size_t		ft_args(char *s, size_t i, unsigned long long int arg);
void		ft_disp(char bin[], unsigned long long arg);
char		ft_val_conv(char *s, size_t i, unsigned long long int arg);
size_t		ft_putstr_fd_c(char *s, int fd, char c);
void		ft_putstr_fd(char *s, int fd);
void		ft_putchar_fd(char c, int f);
void		ft_putnbr_fd(int n, int fd);
char		ft_cinset(char c, const char *set);
#endif