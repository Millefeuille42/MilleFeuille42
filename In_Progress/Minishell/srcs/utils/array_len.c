#include "minishell.h"

int	array_len(char **array)
{
	int i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}
