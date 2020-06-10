/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:32:33 by dboyer            #+#    #+#             */
/*   Updated: 2020/05/08 18:59:21 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef LIBFT_H
#	define LIBFT_H
#	include <stdlib.h>
#	include <unistd.h>
#	include <stdarg.h>
#	include <fcntl.h>
#	include "libft_objects.h"
#	define CONVERTER "cspdiuxX%"

int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isspace(int c);
int					ft_isprint(int c);
int					ft_islower(int c);
int					ft_isupper(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_cinset(const char c, const char *set);
double				ft_abs(double nb);
int					ft_nspace(char *str);
int					ft_isflag(const char *flag);
int					ft_print(t_format format, va_list *va);
int					ft_print_percent(t_format format);
int					ft_print_char(t_format format, va_list *va);
int					ft_print_str(t_format format, va_list *va);
int					ft_print_nb(t_format format, va_list *va);
int					ft_print_unsigned_nb(t_format format, va_list *va);
int					ft_print_nb_hex(t_format format, va_list *va);
int					ft_print_memory(t_format format, va_list *va);
int					ft_print_space_before(t_format format);
int					ft_print_space_after(t_format format);
int					ft_print_zero_padding(t_format format);
int					ft_printf(const char *str, ...);
int					get_next_line(int fd, char **line);
size_t				ft_strlen(const char *str);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t				ft_nbrlen(long nb);
size_t				ft_nbrlen_unsigned(unsigned int nb);
size_t				ft_nbrlen_base(long nb, int n_base);

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_itoa(int n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnstr(const char *haystack, const char *needle,\
					size_t len);
char				*ft_strdup(const char *s1);
char				*ft_substr(const char *s, unsigned int start, size_t len);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strtrim(const char *s1, const char *set);
char				*ft_str_tolower(char *str);
char				*ft_str_toupper(char *str);
char				*ft_strrev(char *str);
char				*ft_getflag(const char *occurence);

char				**ft_split(const char *s, char c);

void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(long nb, int fd);
void				ft_bzero(void *s, size_t n);
void				ft_putchar(char c);
void				ft_putstr(char *str);
void				ft_split_clean(char **split);
void				ft_putnbr_hex(long nb, char *base, char *neg);
void				ft_putnbr_unsigned(unsigned int nb);
void				ft_putnstr(char *str, int n);

void				*ft_memset(void *b, int c, size_t len);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_calloc(size_t count, size_t size);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);

t_format			ft_minmax(t_format format, int nbrlen);
t_format			ft_minmax_str(t_format format, char *arg);
t_format			ft_minmax_nb(t_format format, int arg);
t_format			ft_minmax_nb_hex(t_format format, int arg);
t_format			ft_minmax_unsigned_nb(t_format format, unsigned int arg);
t_format			ft_minmax_memory(t_format format, long arg);
t_format			ft_parsing(t_format format, va_list *va);
t_format			ft_format(char *flag, va_list *va);

#	endif
