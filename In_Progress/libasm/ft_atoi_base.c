//
// Created by millefeuille on 20/05/2020.
//

#include <stdio.h>

int ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_p(int nb, int power)
{
	int nb2;

	nb2 = nb;
	if (nb == 0)
		return (0);
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	if (power == 1)
		return (nb);
	while (power > 1)
	{
		nb = nb2 * nb;
		power--;
	}
	return (nb);
}

static	int		ft_cinset(const char c, const char *set)
{
	int i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int		check_base(char *base)
{
	int i;

	i = 0;
	while (base[i])
		if (ft_cinset(base[i++], "\t\n\r\v\f "))
			return (1);
	return (0);
}

static int base_to_dec(char c, const char *base, int ret, int pos)
{
	int base_len;
	int i;

	i = 0;
	base_len = ft_strlen(base);
	if (!ft_cinset(c, base))
		return (-1);
	while (c != base[i])
		i++;
	ret = ret + i * ft_p(base_len, pos);
	return (ret);
}

int	ft_atoi_base(char *str, char *base)
{
	int i;
	int result;
	char flag;

	if (check_base(base) || !base || !*base || !str || !*str)
		return (0);
	i = 0;
	flag = 0;
	result = 0;
	while (ft_cinset(*str, "\t\n\r\v\f "))
		str++;
	while (ft_cinset(*str, "+-"))
	{
		flag = 1;
		str++;
		i = 1;
	}
	if (flag)
		str--;
	while (str[i] && ft_cinset(str[i], base) && (result = base_to_dec(str[i], base, result, ft_strlen(str) - 1 - i)) >= 0)
		i++;
	return (str[0] == '-') ? result * -1 : result;
}

int main(int argc, char *argv[])
{
	printf("%d", ft_atoi_base(argv[1], "012"));
	return (0);
}
