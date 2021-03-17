//
// Created by millefeuille on 16/03/2021.
//

#include "../includes/commons.h"

void	safe_free(void **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}
