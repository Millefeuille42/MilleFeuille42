#include <AudioUnit/AudioUnit.h>
#include "minishell.h"
#include "parsing.h"

int		iter_until_set(char *str, char *set)
{
	int i;

	i = 0;
	while (str[i] && !ft_cinset(str[i], set))
		i++;
	return (i);
}

char	is_escape(const char *str, int i)
{
	char is;

	is = 0;
	if (i == 0)
		return (0);
	i--;
	while (i >= 0 && str[i] == '\\')
	{
		is = (char)!is;
		i--;
	}
	return (is);
}

int		skip_wp(char *input, int i)
{
	while (input[i] && ft_isspace(input[i]))
		i++;
	return (i);
}

int		skip_quote(const char *input, int i, char quote)
{
	i++;
	while (input[i] && !(input[i] == quote && !is_escape(input, i)))
		i++;
	if (input[i])
		i++;
	return (i);
}

char	**delete_entry(char **arr, int entry)
{
	char	**ret;
	int		len;
	int		i;
	int		i2;

	len = ft_len(arr);
	if (!(ret = malloc(sizeof(char *) * (len))))
		return (NULL);
	ret[len - 1] = NULL;
	i = 0;
	i2 = 0;
	while (arr[i])
	{
		if (i != entry)
		{
			ret[i2] = arr[i];
			i2++;
		}
		else if (i == entry)
			free(arr[i]);
		i++;
	}
	return (ret);
}
