/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 09:15:20 by dboyer            #+#    #+#             */
/*   Updated: 2020/10/21 17:38:26 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	int		ft_is_env_var(char *str)
{
	if (str && *str == '$' && !ft_is_escape(str))
	{
		while (ft_isalnum(*str) || *str == '?')
		{
			if (*str == '?')
				return (1);
			str++;
		}
		return (*str == '$' || !*str ? 1 : 0);
	}
	return (0);
}

static	int		get_var_len(char *str)
{
	int i;

	i = 0;
	while (str && str[i] && (ft_isalnum(str[i]) || str[i] == '?'))
	{
		if (str[i] == '?')
			return (i + 1);
		i++;
	}
	return (i);
}

static	char	*replace(t_shell *shell, char *input, char **ret)
{
	char	*tmp;
	char	*value;
	int		key_len;

	key_len = get_var_len(&input[1]);
	tmp = ft_substr(input, 1, key_len);
	value = shell->env_get(shell, tmp);
	free(tmp);
	if (value)
	{
		tmp = ft_strdup(*ret);
		*ret = *ret ? ft_strjoin(tmp, value) : ft_strdup(value);
		free(tmp);
	}
	return (&input[key_len + 1]);
}

static	char	*add_to(char *input, char **ret)
{
	char	*tmp;
	char	*tmp2;

	if (input && ret)
	{
		if (!(tmp = malloc(sizeof(char) * 2)))
			return (NULL);
		tmp[0] = input[0];
		tmp[1] = '\0';
		if (*ret)
		{
			tmp2 = ft_strjoin(*ret, tmp);
			free(*ret);
			free(tmp);
			*ret = tmp2;
		}
		else
			*ret = tmp;
		return (&input[1]);
	}
	return (NULL);
}

char			*ft_replace_input(t_shell *shell, char *input)
{
	char	*ret;
	char	*tmp;
	char	quote;

	ret = NULL;
	quote = 0;
	while (input && *input)
	{
		if (*input == quote && !ft_is_escape(input))
			quote = 0;
		else
			quote = *input == '\'' && !ft_is_escape(input) ? *input : quote;
		if (ft_is_env_var(input) && ft_cinset(';', ret) <= 0 && !quote)
			input = replace(shell, input, &ret);
		else
			input = add_to(input, &ret);
	}
	if (ret)
	{
		tmp = ft_strtrim(ret, " ");
		ft_safe_free((void **)&ret);
		ret = tmp;
	}
	return (ret);
}
