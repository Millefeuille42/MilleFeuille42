#include "echo.h"

int	main(int argc, char *argv[])
{
	int		i;
	char	n;

	i = 1;
	n = 1;
	while (i < argc)
	{
		if (i == 1 && !ft_strncmp("-n", argv[i], 2))
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
}
