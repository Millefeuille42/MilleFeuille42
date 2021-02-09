/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_stdout_redirect.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 16:08:15 by dboyer            #+#    #+#             */
/*   Updated: 2020/10/29 12:13:09 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		fd_error(t_shell *shell, char *path)
{
	shell->ret = 1;
	shell->loop = 0;
	ft_print_error("minishell: %s : %s\n", path, strerror(errno));
}

static	void	open_file(t_shell *shell, t_command *cmd)
{
	char	**path;
	int		i;

	i = 0;
	path = ft_sort_arg(cmd->redirect.dest.content);
	while (path[i])
	{
		if (*path[i] && cmd->redirect.type == 2)
			cmd->actual_fd = open(path[i],\
				O_WRONLY | O_TRUNC | O_CREAT, 00644);
		else if (*path[i] && cmd->redirect.type == 3)
			cmd->actual_fd = open(path[i],\
				O_WRONLY | O_APPEND | O_CREAT, 00644);
		if (*path[i] && cmd->actual_fd > 0 && path[i + 1])
			close(cmd->actual_fd);
		else if (*path[i] && cmd->actual_fd < 0)
			fd_error(shell, path[i]);
		i++;
	}
	if (cmd->actual_fd < 0)
		ft_safe_free((void **)&cmd->command);
	ft_split_clean(&path);
}

static int		ft_is_dest(char *str, int quote)
{
	return ((ft_isseparator(*str) != 1 && *str != ' ') ||\
			(*str == ' ' && ft_is_escape(str)) ||\
			(((ft_isseparator(*str) == 1 && ft_is_escape(str)) ||\
			(ft_isseparator(*str) == 1 && quote))));
}

static char		*handle(t_shell *shell, t_command *cmd, char *str)
{
	char	*tmp;

	str = ft_safe_extract(shell, str, &tmp, ft_is_dest);
	cmd->redirect.dest.push(&cmd->redirect.dest, " ");
	cmd->redirect.dest.push(&cmd->redirect.dest, tmp);
	str = ft_move_until(str, "not", ft_isspace);
	if (str && *str == '>')
		return (ft_handle_stdout_redirect(shell, cmd, str));
	if (str && !ft_isseparator(*str))
	{
		safe_free((void **)&tmp);
		str = ft_safe_extract(shell, str, &tmp, ft_isarg);
		cmd->argv.push(&cmd->argv, " ");
		cmd->argv.push(&cmd->argv, tmp);
	}
	if (!str || (str && !*str) || *str == ';')
		open_file(shell, cmd);
	if (cmd->actual_fd > 0)
		cmd->stdout = dup2(cmd->actual_fd, STDOUT_FILENO);
	safe_free((void **)&tmp);
	return (str);
}

char			*ft_handle_stdout_redirect(t_shell *shell,\
				t_command *cmd, char *str)
{
	if (*str == '>' && *(str + 1) == '>')
		cmd->redirect.type = 3;
	else if (*str == '>' && *(str + 1) != '>')
		cmd->redirect.type = 2;
	str = cmd->redirect.type == 3 ? &str[2] : &str[1];
	str = ft_move_until(str, "not", ft_isspace);
	if (str && *str && !ft_isseparator(*str))
		str = handle(shell, cmd, str);
	else if (str && *str)
	{
		shell->ret = 1;
		shell->loop = 0;
		ft_print_error("%s << %c >>\n", SYNTAX_ERROR, *str);
	}
	else
		ft_syntax_error(shell);
	return (str);
}
