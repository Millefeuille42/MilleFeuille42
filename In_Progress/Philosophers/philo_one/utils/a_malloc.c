//
// Created by millefeuille on 2/12/21.
//

#include "../philo_one.h"

int		a_malloc(void **ptr, size_t size) {
	*ptr = malloc(size);
	if (!*ptr)
		return (1);
	return (0);
}
