//
// Created by millefeuille on 2/22/21.
//

#include "../philo_one.h"

void	ft_milli_sleep_interrupt(unsigned long	time, const char *interrupt) {
	unsigned long tts;

	tts = get_cur_time() + time;
	while (get_cur_time() < tts && *interrupt) {
		usleep(500);
	}
}

void	ft_milli_sleep(unsigned long time) {
	unsigned long tts;

	tts = get_cur_time() + time;
	while (get_cur_time() < tts) {
		usleep(500);
	}
}