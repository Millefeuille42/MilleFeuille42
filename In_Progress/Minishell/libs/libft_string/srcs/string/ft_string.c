/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 19:08:35 by dboyer            #+#    #+#             */
/*   Updated: 2020/05/18 10:58:51 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/string_object.h"

static inline void	init_string(t_string *this)
{
	this->clear = ft_clear_string;
	this->push = ft_push_string;
	this->upper = ft_string_up;
	this->prepend = ft_prepend;
	this->lower = ft_string_low;
	this->replace = ft_replace;
	this->delete = ft_delete;
}

t_string			ft_string(char *str)
{
	t_string this;

	this.size = ft_strlen(str);
	this.content = ft_strdup(str);
	init_string(&this);
	return (this);
}
