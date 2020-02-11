/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 16:54:36 by mlabouri          #+#    #+#             */
/*   Updated: 2020/02/10 12:19:13 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define FLAGS "-0.*+"
# define INTS "diuxX"
# define ALL "cspdiuxX%-0.*"
# define HEXX "0123456789ABCDEF"
# define HEX "0123456789abcdef"

# include <stdarg.h>
# include <string.h>
# include <unistd.h>

extern int	g_count;
extern int	(*g_func_length[255])(char, unsigned long long int);
extern void	(*g_func_conv[255])(unsigned long long int);
extern int	(*g_func_fval[255])(const char *, size_t, va_list *);
extern void	(*g_func_fdisp[255])(int[], unsigned long long int, char);

size_t				ft_args(char *s, size_t i, va_list *args);
void				ft_disp_convs(unsigned long long arg, char conv);
void				ft_disp_flags(int bin[], unsigned long long arg, char conv);

void				ft_putchar_fd(char c, int f);
void				ft_putnbr_fd(long n, int fd);
void				ft_putunbr(unsigned int nb);
void				ft_putnbrbase(unsigned long n, char *base);
size_t				ft_putstr_fd_c(char *s, int fd, char c, size_t i);
void				ft_putstr_fd(char *s, int fd);
void				ft_putnstr(char *s, int len);

char				ft_cinset(char c, const char *set);
int					ft_isdigit(int c);
int					ft_isdigit0(int c);
int					ft_power(int nb, int power);
void				ft_szero(int *s, size_t n);
long int			int_abs(int nb);
int					atoi_mk2(const char *s, int start, int end);

size_t				ft_strlen(const char *str);
int					ft_nbr_len(int n);
int					ft_unbr_len(unsigned int nb);
int					ft_nbrbase_len(unsigned long nb, char *base);

#endif
