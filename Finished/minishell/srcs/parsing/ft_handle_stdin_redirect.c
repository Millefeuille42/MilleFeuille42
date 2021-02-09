/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_stdin_redirect.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 13:41:55 by dboyer            #+#    #+#             */
/*   Updated: 2020/10/29 10:44:48 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_files(t_shell *shell, char **files)
{
	int	fd;

	while (files && *files)
	{
		fd = open(*files, O_RDONLY);
		if (fd < 0)
		{
			shell->ret = 1;
			shell->loop = 0;
			ft_print_error("minishell: %s: %s\n", *files, strerror(errno));
			return (fd);
		}
		if (*files && !*(files + 1))
			return (fd);
		files++;
	}
	return (-1);
}

static char	*handle(t_shell *shell, t_command *cmd, char *str)
{
	char *tmp;
	char **files;

	str = ft_safe_extract(shell, str, &tmp, ft_isarg);
	str = ft_move_until(str, "not", ft_isspace);
	if (str && !ft_isseparator(*str))
	{
		safe_free((void **)&tmp);
		return (ft_handle_stdin_redirect(shell, cmd, str));
	}
	files = ft_sort_arg(tmp);
	if (files)
		cmd->actual_fd = check_files(shell, files);
	if (cmd->actual_fd > 0)
		cmd->stdin = dup2(cmd->actual_fd, STDIN_FILENO);
	safe_free((void **)&tmp);
	ft_split_clean(&files);
	return (str);
}

char		*ft_handle_stdin_redirect(t_shell *shell, t_command *cmd, char *str)
{
	str = str && !ft_isseparator(*(str + 1)) ? str + 1 : str;
	if (str && !ft_isseparator(*str))
	{
		if (str)
			str = handle(shell, cmd, str);
		else
			ft_syntax_error(shell);
	}
	else
	{
		shell->ret = 2;
		shell->loop = 0;
		ft_print_error("%s << %c >>\n", SYNTAX_ERROR, *str);
	}
	if (cmd->actual_fd < 0)
		ft_safe_free((void **)&cmd->command);
	return (str);
}
