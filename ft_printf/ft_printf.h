#ifndef FT_PRINTF_H
#define FT_PRINTF_H

# include <stdarg.h>
# include <string.h>

size_t		ft_count_args(const char *s);
int			ft_val_arg(const char *s, size_t i);
int			ft_val_flags(const char *s, size_t i, char flag);
size_t		ft_strlen(const char *str);
char		ft_cinset(const char c, const char *set);
#endif
