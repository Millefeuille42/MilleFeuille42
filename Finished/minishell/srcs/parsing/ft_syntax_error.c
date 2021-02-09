/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syntax_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 16:06:24 by dboyer            #+#    #+#             */
/*   Updated: 2020/10/29 12:14:19 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_syntax_error(t_shell *shell)
{
	shell->ret = 2;
	shell->loop = 0;
	ft_print_error("%s << newline >>\n", SYNTAX_ERROR);
}
