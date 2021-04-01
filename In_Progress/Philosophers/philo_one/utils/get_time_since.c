//
// Created by millefeuille on 2/16/21.
//

#include "../philo_one.h"

unsigned long 	get_time_since(unsigned long  tm) {
	unsigned long 			ret;

	ret = get_cur_time() - tm;
	return (ret);
}
