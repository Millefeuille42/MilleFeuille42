/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_prompt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 16:29:28 by dboyer            #+#    #+#             */
/*   Updated: 2020/06/11 16:32:40 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_show_prompt(t_shell *shell)
{
	shell->prompt = ft_getcwd();
	ft_printf("(minishell) %s $ ", shell->prompt.content);
	shell->prompt.clear(&shell->prompt);
}
