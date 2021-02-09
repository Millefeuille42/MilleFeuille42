/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 19:58:03 by dboyer            #+#    #+#             */
/*   Updated: 2020/10/28 08:43:50 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*correct_path(t_shell *shell, char *path)
{
	char *home;

	if (ft_strlen(path) >= 2 && path[0] == '~' && path[1] == '/')
	{
		home = shell->env_get(shell, "HOME");
		return (ft_strjoin(home, &path[1]));
	}
	return (ft_strdup(path));
}

static	int	change_directory(t_shell *shell, char *path)
{
	shell->replace_env(shell, ft_strdup("OLDPWD"), \
	ft_strdup(shell->env_get(shell, "PWD")));
	return (chdir(path));
}

static	int	change_to_home(t_shell *shell)
{
	char *home;

	home = shell->env_get(shell, "HOME");
	if (home)
	{
		change_directory(shell, home);
		shell->replace_env(shell, ft_strdup("PWD"), ft_strdup(home));
		return (0);
	}
	ft_putstr_fd("cd: HOME variable not set\n", STDERR_FILENO);
	return (1);
}

static int	update_environment(t_shell *shell, char *argv[])
{
	t_string	cwd;

	cwd = ft_getcwd();
	if (cwd.content)
	{
		shell->replace_env(shell, ft_strdup("PWD"), ft_strdup(cwd.content));
		cwd.clear(&cwd);
		return (0);
	}
	else
	{
		ft_print_error("cd: error: %s is not accessible\n", argv[1]);
		return (1);
	}
}

int			ft_cd(t_shell *shell, char *argv[])
{
	size_t		argc;
	char		*path;

	argc = ft_len(argv);
	if (argc > 2)
	{
		ft_print_error("cd: string not in pwd: %s\n", argv[1]);
		return (1);
	}
	if (argc == 1 || (argc == 2 && (ft_str_isequal("~", argv[1])
					|| ft_str_isequal("~/", argv[1]))))
		return (change_to_home(shell));
	path = correct_path(shell, argv[1]);
	if (argc == 2 && change_directory(shell, path))
	{
		safe_free((void **)&path);
		ft_print_error("cd error: %s: %s\n", argv[1], strerror(errno));
		return (1);
	}
	safe_free((void **)&path);
	return (update_environment(shell, argv));
}
