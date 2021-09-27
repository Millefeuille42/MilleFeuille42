//
// Created by Millefeuille on 11/06/2021.
//

#include "client.h"

void	send_and_wait_ack(int pid, int sig)
{
	kill(pid, sig);
	pause();
	usleep(20);
}

void	encode(const char *str, int pid)
{
	int		i;
	int		i2;
	char	cur;

	i = 0;
	while (str[i])
	{
		i2 = 0;
		cur = str[i] / 10;
		while (i2 < cur + 1)
		{
			send_and_wait_ack(pid, SIGUSR1);
			i2++;
		}
		send_and_wait_ack(pid, SIGUSR2);
		i2 = 0;
		while (i2 < (str[i] + 1) - cur * 10)
		{
			send_and_wait_ack(pid, SIGUSR1);
			i2++;
		}
		send_and_wait_ack(pid, SIGUSR2);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		ft_putstr("Invalid number of arguments!\n");
		return (1);
	}
	setup();
	if (!ft_is_string_digit(argv[1]))
	{
		ft_putstr("Invalid pid!\n");
		return (1);
	}
	pid = (int)ft_atoi(argv[1]);
	ft_putstr("Sending Message to ");
	ft_putnbr(pid, 1);
	write(1, "\n", 1);
	send_and_wait_ack(pid, SIGUSR2);
	send_and_wait_ack(pid, SIGUSR2);
	encode(argv[2], pid);
	send_and_wait_ack(pid, SIGUSR2);
	pause();
}
