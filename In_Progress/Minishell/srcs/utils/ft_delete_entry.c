#include "minishell.h"

char	**ft_delete_entry(char **array, int index)
{
	char	**temp;
	int		i;
	int		i2;

	if (!(temp = malloc(sizeof(char *) * (array_len(array)))))
		return (NULL);
	i = 0;
	i2 = 0;
	while (array[i])
	{
		if (i == index)
		{
			free(array[i]);
			array[i++] = NULL;
		}
		else
		{
			temp[i2] = array[i++];
			i2++;
		}
	}
	temp[i2] = NULL;
	free(array);
	array = NULL;
	return (temp);
}
