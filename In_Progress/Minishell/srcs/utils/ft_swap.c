//
// Created by Mathieu LABOURIER on 7/6/20.
//

void	ft_swap_int(int *i1, int *i2)
{
	int temp;

	temp = *i1;
	*i1 = *i2;
	*i2 = temp;
}