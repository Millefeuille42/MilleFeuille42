#include "server.h"

char	message_start_stop(void)
{
	if (*get_last() == body)
	{
		if (*get_status() == rx1)
		{
			*get_mess() = *get_mess() - 1;
			*get_mess() *= 10;
			*get_status() = rx2;
		}
		else if (*get_status() == rx2)
		{
			*get_mess() = *get_mess() - 1;
			write(1, &*get_mess(), 1);
			*get_mess() = 0;
			*get_status() = stop;
		}
		return (1);
	}
	return (0);
}

int	main(void)
{
	setup();
	ft_putstr("Server Started on PID: ");
	ft_putnbr(getpid(), 1);
	write(1, "\n", 1);
	while (1)
		sleep(100);
}
