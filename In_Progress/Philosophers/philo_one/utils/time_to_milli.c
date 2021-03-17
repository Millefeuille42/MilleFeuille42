//
// Created by millefeuille on 2/17/21.
//

#include "../philo_one.h"

long	get_cur_time() {
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time_to_milli(time));
}

long	time_to_milli(struct timeval time) {
	return ((time.tv_usec / 1000) + time.tv_sec * 1000);
}