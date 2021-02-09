/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 18:20:43 by dboyer            #+#    #+#             */
/*   Updated: 2020/10/27 17:56:32 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	char	*clean_command(t_shell *shell, char *cmd)
{
	char	*path;
	char	**path_splitted;
	char	*ret;
	int		i;

	i = 0;
	path = shell->env_get(shell, "PATH");
	if (path)
	{
		path_splitted = ft_split(path, ':');
		while (path_splitted && path_splitted[i])
		{
			if ((ret = ft_find_command(path_splitted[i], cmd)))
			{
				ft_split_clean(&path_splitted);
				return (ret);
			}
			i++;
		}
		if (path_splitted)
			ft_split_clean(&path_splitted);
		return (cmd);
	}
	return (cmd);
}

static	void	clean(char **tmp)
{
	char *ret;

	if ((ret = clean_quotes(*tmp)))
	{
		safe_free((void **)tmp);
		*tmp = ret;
	}
	if ((ret = clean_backslash(*tmp)))
	{
		safe_free((void **)tmp);
		*tmp = ret;
	}
}

char			*ft_get_command(char *str, t_shell *shell, t_command *cmd)
{
	char	*tmp;

	str = ft_move_until(str, "not", ft_is_sep_and_space);
	str = ft_safe_extract(shell, str, &tmp, ft_iscommand);
	clean(&tmp);
	cmd->command = clean_command(shell, tmp);
	cmd->argv.push(&cmd->argv, cmd->command);
	if (tmp != cmd->command)
		safe_free((void **)&tmp);
	return (str);
}
