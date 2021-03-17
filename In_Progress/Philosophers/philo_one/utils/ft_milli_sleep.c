//
// Created by millefeuille on 2/22/21.
//

#include "../philo_one.h"

void	ft_milli_sleep_interrupt(long time, const char *interrupt) {
	int i;

	i = 0;
	if (time <= 0)
		return ;
	while (i < time || *interrupt) {
		usleep(1000);
		i++;
	}
	if (!*interrupt)
		printf("\tINTERRUPT\n");
}

void	ft_milli_sleep(long time) {
	int i;

	i = 0;
	if (time <= 0)
		return ;
	while (i < time) {
		usleep(1000);
		i++;
	}
}