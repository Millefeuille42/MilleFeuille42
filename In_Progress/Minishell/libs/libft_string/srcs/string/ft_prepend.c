/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prepend.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 22:03:49 by mlabouri          #+#    #+#             */
/*   Updated: 2020/05/18 10:58:51 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft_string.h"

void	ft_prepend(struct s_string *this, const char *new_str)
{
	int		i;
	int		i2;
	char	*ret;

	if (!this->content || !this->content[0] || !new_str || !new_str[0])
		return ;
	i2 = (int)ft_strlen(new_str);
	if (!(ret = malloc(sizeof(char) * (this->size + i2 + 1))))
		return ;
	i = 0;
	while (new_str[i])
	{
		ret[i] = new_str[i];
		i++;
	}
	i2 = 0;
	while (this->content[i2])
	{
		ret[i2 + i] = this->content[i2];
		i2++;
	}
	ret[i2 + i] = '\0';
	this->clear(this);
	this->size = ft_strlen(ret);
	this->content = ret;
}
