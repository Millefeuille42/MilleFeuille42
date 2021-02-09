/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isarg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 17:44:34 by mlabouri          #+#    #+#             */
/*   Updated: 2020/10/21 17:44:34 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_isarg(char *str, int quote)
{
	return (ft_isseparator(*str) != 1 ||\
			(((ft_isseparator(*str) == 1 && ft_is_escape(str)) ||\
			(ft_isseparator(*str) == 1 && quote))));
}
