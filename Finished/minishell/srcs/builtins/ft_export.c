/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 15:01:46 by dboyer            #+#    #+#             */
/*   Updated: 2020/10/27 16:28:39 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	void	update_join(t_shell *shell,\
							char *key, char *value, size_t keylen)
{
	char	*key_tmp;
	char	*val_tmp;
	char	*val;

	val_tmp = NULL;
	key_tmp = ft_substr(key, 0, keylen - 1);
	val = shell->env_get(shell, key_tmp);
	if (val)
	{
		val_tmp = ft_strjoin(val, value);
		shell->replace_env(shell, key_tmp, val_tmp);
	}
	else
		shell->add_env(shell, key_tmp, value);
}

static	int		key_is_valid(char *str)
{
	while (str && *str)
	{
		if (!ft_isalnum(*str) && *str != '+')
			return (0);
		str++;
	}
	return (1);
}

static	void	update_env(t_shell *shell, char *key, char *value)
{
	char	*val;
	size_t	keylen;

	keylen = strlen(key);
	if (key[keylen - 1] == '+')
		update_join(shell, key, value, keylen);
	else if (ft_cinset(key[keylen - 1], "*-/") || !*key ||\
			!key_is_valid(key))
		ft_print_error(\
		"minishell: export << %=%s >> identifiant non valable\n", key, value);
	else
	{
		val = shell->env_get(shell, key);
		if (val)
			shell->replace_env(shell, key, value);
		else
			shell->add_env(shell, key, value);
	}
}

static	void	export(t_shell *shell, char **argv)
{
	char	**splitted;

	splitted = ft_extract_env(argv[1]);
	if (splitted)
	{
		update_env(shell, splitted[0], splitted[1]);
		safe_free((void **)&splitted);
	}
	else if (!splitted && argv[2])
		ft_print_error(\
		"minihsell: export: << %s >> : identifiant non valable\n", argv[2]);
}

int				ft_export(t_shell *shell, char *argv[])
{
	size_t	argc;

	argc = ft_len(argv);
	if (argc == 1)
	{
		shell->print_env(shell);
		return (0);
	}
	export(shell, argv);
	return (0);
}
