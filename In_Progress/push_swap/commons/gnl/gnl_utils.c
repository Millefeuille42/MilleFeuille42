#include "../includes/commons.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	if (str != NULL)
	{
		i = 0;
		while (str[i])
			i++;
		return (i);
	}
	return (0);
}

char	*ft_strchr(const char *s, int c)
{
	if (s != NULL)
	{
		while (*s && *s != c)
			s++;
		if (*s != c)
			return (NULL);
		return ((char *)s);
	}
	return (NULL);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub;

	i = 0;
	while (s[(size_t)start + i] != '\0' && i < len)
		i++;
	sub = malloc(sizeof(char) * i + 1);
	if (!sub)
		return (NULL);
	i = 0;
	while (s[(size_t)start + i] != '\0' && i < len)
	{
		sub[i] = s[(size_t)start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	i2;
	char	*join;

	i = 0;
	i2 = 0;
	join = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!join)
		return (NULL);
	while (s1[i] != '\0')
	{
		join[i] = s1[i];
		i++;
	}
	while (s2[i2] != '\0')
	{
		join[i + i2] = s2[i2];
		i2++;
	}
	join[i + i2] = '\0';
	return (join);
}
