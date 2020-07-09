//
// Created by Mathieu LABOURIER on 7/9/20.
//

#include "minishell.h"
#include "parsing.h"

int		delete_char(char **str, int pos)
{
	char	*ret;
	int		len;
	int		i;
	int		i2;

	len = ft_strlen(*str);
	if (!(ret = malloc(sizeof(char) * (len))))
		return (ERRMALLOC);
	ret[len - 1] = '\0';
	i = 0;
	i2 = 0;
	while ((*str)[i])
	{
		if (i != pos)
		{
			ret[i2] = (*str)[i];
			i2++;
		}
		i++;
	}
	free(*str);
	*str = ret;
	return (0);
}