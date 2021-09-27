//
// Created by Millefeuille on 21/06/2021.
//

#include "../minitalk.h"

void	do_ack(int sig, siginfo_t *info, void *context)
{
	(void)sig;
	(void)context;
	ft_putstr("FROM: ");
	ft_putnbr(info->si_pid, 1);
	ft_putstr(" - Message received\n");
	exit(0);
}

void	message_ok(int sig, siginfo_t *info, void *context)
{
	(void)sig;
	(void)info;
	(void)context;
}

void	setup(void)
{
	struct sigaction	sigusr_1;
	struct sigaction	sigusr_2;

	sigusr_1.sa_sigaction = message_ok;
	sigaction(SIGUSR1, &sigusr_1, NULL);
	sigusr_2.sa_sigaction = do_ack;
	sigaction(SIGUSR2, &sigusr_2, NULL);
}
