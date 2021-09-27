//
// Created by Millefeuille on 21/06/2021.
//

#include "server.h"

void	send_ack(siginfo_t *info, int sig, int delay)
{
	usleep(delay - 30);
	kill(info->si_pid, sig);
}

void	message_decrypt(int sig, siginfo_t *info, void *context)
{
	(void)sig;
	(void)context;
	if (*get_status() == stop)
		*get_status() = rx1;
	*get_mess() = *get_mess() + 1;
	*get_last() = body;
	send_ack(info, SIGUSR1, 50);
}

void	message_catch(int sig, siginfo_t *info, void *context)
{
	(void)sig;
	(void)context;
	if (!message_start_stop() && *get_last() == status)
	{
		if (*get_status() == stop)
		{
			write(1, "\n\n", 2);
			*get_mess() = 0;
			*get_status() = off;
			*get_last() = none;
			send_ack(info, SIGUSR1, 50);
			send_ack(info, SIGUSR2, 500);
			return ;
		}
		if (*get_status() == off)
			*get_status() = rx1;
	}
	*get_last() = status;
	send_ack(info, SIGUSR1, 50);
}

void	setup(void)
{
	struct sigaction	sigusr_1;
	struct sigaction	sigusr_2;

	*get_mess() = 0;
	*get_status() = off;
	*get_last() = none;
	sigusr_1.sa_sigaction = message_decrypt;
	sigaction(SIGUSR1, &sigusr_1, NULL);
	sigusr_2.sa_sigaction = message_catch;
	sigaction(SIGUSR2, &sigusr_2, NULL);
}
