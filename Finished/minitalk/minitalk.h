#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

enum e_last {
	none,
	body,
	status
};

enum e_status {
	off,
	rx1,
	rx2,
	stop
};

void	ft_putstr(const char *str);
void	ft_putnbr(int n, int fd);
int		ft_isdigit(int c);
int		ft_is_string_digit(char *str);
long	ft_atoi(const char *str);

#endif
