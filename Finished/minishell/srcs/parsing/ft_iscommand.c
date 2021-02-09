/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iscommand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 17:45:20 by mlabouri          #+#    #+#             */
/*   Updated: 2020/10/21 17:45:20 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_iscommand(char *str, int quote)
{
	return ((*str == ' ' && quote) ||\
			(ft_isseparator(*str) && quote) ||
			(ft_isseparator(*str) && ft_is_escape(str)) ||\
			!ft_is_sep_and_space(*str));
}
