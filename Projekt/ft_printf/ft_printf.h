#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define FLAGS "-0.*"
# define CONVS "cspdiuxX%"

# include <stdarg.h>
# include <string.h>
# include <stdio.h> //remove
# include <unistd.h>

char		ft_val_flag(const char *s, size_t i);
char		ft_val_conv(const char *s, size_t i, void **arg);
size_t		ft_putstr_fd_c(const char *s, int fd, char c);
char		ft_cinset(const char c, const char *set);
#endif
