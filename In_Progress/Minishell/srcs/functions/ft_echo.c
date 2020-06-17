#include "minishell.h"

int		ft_echo(char *argv[])
{
	int		i;
	char	n;
	int		argc;

	i = 1;
	n = 1;
	argc = ft_len(argv);
	while (argv[i])
	{
		if (i == 1 && ft_str_isequal("-n", argv[i]))
			n = 0;
		else
		{
			ft_putstr(argv[i]);
			if (i < argc - 1)
				ft_putchar(' ');
		}
		i++;
	}
	if (n == 1)
		ft_putchar('\n');
	return (0);
}
