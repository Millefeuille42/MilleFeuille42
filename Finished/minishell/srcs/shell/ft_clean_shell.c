/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_shell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 13:19:37 by dboyer            #+#    #+#             */
/*   Updated: 2020/10/09 13:19:54 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_clean_shell(t_shell *shell)
{
	shell->lst_cmd.iter(shell->lst_cmd.first, ft_del_cmd);
	shell->lst_cmd.clear(&shell->lst_cmd);
	shell->clear_env(shell);
	if (shell->input)
		safe_free((void **)&shell->input);
}
