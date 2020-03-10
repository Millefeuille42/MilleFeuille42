/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 10:30:08 by mlabouri          #+#    #+#             */
/*   Updated: 2020/03/10 14:31:15 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define FLAGS "-0.*+"
# define INTS "diuxX"
# define ALL "cspdiuxX%-0.*"
# define HEXX "0123456789ABCDEF"
# define HEX "0123456789abcdef"
# define INT_MIN -2147483648

# include <stdarg.h>
# include <string.h>
# include <unistd.h>

struct			s_f
{
	int			dotc;
	int			dot;
	int			zero;
	int			minus;
	int			pad;
	int			length;
};

struct			s_c
{
	unsigned	diux;
	long		p;
	char		ch;
	char		*s;
};

extern int		g_count;
extern int		(*g_func_length[255])(char, struct s_c, struct s_f *);
extern void		(*g_func_conv[255])(struct s_c);

int				ft_printf(const char *input, ...);
size_t			ft_args(char *s, size_t i, va_list *args);
void			ft_disp_convs(struct s_c arg, char conv);
void			ft_disp_flags(struct s_f bin, struct s_c arg, char conv);
void			ft_putchar_fd(char c, int f);
void			ft_putnbr_fd(unsigned long int n, int fd, char flag);
void			ft_putunbr(unsigned int nb);
void			ft_putnbrbase(unsigned long n, char *base);
size_t			ft_putstr_fd_c(char *s, int fd, char c, size_t i);
void			ft_putstr_fd(char *s, int fd);
void			ft_putnstr(char *s, int len);
char			ft_cinset(char c, const char *set);
int				ft_isdigit(int c);
int				ft_isdigit0(int c);
int				ft_power(int nb, int power);
void			ft_szero(struct s_f *bin, struct s_c *arg);
long int		int_abs(int nb);
int				atoi_mk2(const char *s, int start, int end);
size_t			ft_strlen(const char *str);
int				ft_nbr_len(int n);
int				ft_unbr_len(unsigned int nb);
int				ft_nbrbase_len(unsigned long nb, char *base);

#endif
