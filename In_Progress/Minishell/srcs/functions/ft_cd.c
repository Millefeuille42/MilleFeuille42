/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 19:58:03 by dboyer            #+#    #+#             */
/*   Updated: 2020/06/23 17:00:29 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static  void	update_env(t_shell *shell, char *path)
{
	shell->env_remove(shell, "PWD");
	shell->add_env(shell, ft_strdup("PWD"), path);
}

static  int	change_to_home(t_shell *shell)
{
	char *home;

	home = shell->env_get(shell, "HOME");
	if (home)
	{
		chdir(home);
		update_env(shell, ft_strdup(home));
		return (0);
	}
	ft_printf("cd: HOME variable not set\n");
	return (1);
}

char				*correct_path(t_shell *shell, char *path)
{
	char *home;

	if (ft_strlen(path) >= 2 && path[0] == '~' && path[1] == '/')
	{
		home = shell->env_get(shell, "HOME");
		return (ft_strjoin(home, &path[1]));
	}
	return (ft_strdup(path));
}

int					ft_cd(t_shell *shell, char *argv[])
{
	t_string	cwd;
	size_t		argc;
	char		*path;

	argc = ft_len(argv);
	if (argc > 2)
	{
		ft_printf("cd: string not in pwd: %s\n", argv[1]);
		return (1);
	}
	if (argc == 1 || (argc == 2 && (ft_str_isequal("~", argv[1])
	|| ft_str_isequal("~/", argv[1]))))
		return (change_to_home(shell));
	path = correct_path(shell, argv[1]);
	if (argc == 2 && chdir(path))
	{
		free(path);
		ft_printf("cd error: %s\n", strerror(errno));
		return (1);
	}
	free(path);
	cwd = ft_getcwd();
	update_env(shell, ft_strdup(cwd.content));
	cwd.clear(&cwd);
	return (0);
}
