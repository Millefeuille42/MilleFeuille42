/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 18:30:02 by dboyer            #+#    #+#             */
/*   Updated: 2020/10/10 19:33:04 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*ft_parse_args(t_shell *shell, char *str, t_command *cmd)
{
	char	*ret;

	str = ft_safe_extract(shell, str, &ret, ft_isarg);
	cmd->argv.push(&cmd->argv, " ");
	cmd->argv.push(&cmd->argv, ret);
	safe_free((void **)&ret);
	return (str);
}
