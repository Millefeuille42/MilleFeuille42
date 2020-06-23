#include "minishell.h"
#include "parsing.h"

static char	**fill_array(char **array, int len)
{
	int i;

	i = 0;
	if (array)
	{
		while (i < len)
		{
			array[i] = ft_strdup("");
			i++;
		}
	}
	return (array);
}

static int	arg_len(char *input, int (*get_next)(char *, int *, char **))
{
	int		i;
	int		count;
	char	*ret;

	if (!input || !input[0])
		return (-ERREMPTY);
	i = 0;
	if ((count = get_next(input, &i, &ret)))
		return (-count);
	if (ret)
		free(ret);
	while (ret)
	{
		get_next(input, &i, &ret);
		if (ret)
			free(ret);
		count++;
	}
	return (count);
}

int			get_n(char *input, int (*g)(char *, int *, char **), char ***ret)
{
	int		i;
	int		len;
	int		index;
	int		err;

	index = 0;
	i = 0;
	len = arg_len(input, g);
	if (len < 0)
		return (-len);
	if (!(*ret = malloc(sizeof(char *) * (len + 1))))
		return (ERRMALLOC);
	(*ret)[len] = NULL;
	while (input[i])
	{
		if ((err = g(input, &i, &(*ret)[index])) && fill_array(*ret, len))
		{
			clear(*ret);
			return (-err);
		}
		index++;
	}
	return (0);
}
