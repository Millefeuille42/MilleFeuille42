/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_safe_extract.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 17:45:20 by mlabouri          #+#    #+#             */
/*   Updated: 2020/10/27 18:41:08 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_str(t_shell *shell, char *str)
{
	char	*tmp2;

	tmp2 = ft_replace_input(shell, str);
	ft_safe_free((void **)&shell->input);
	shell->input = tmp2;
	str = shell->input;
	while (str && *str && *str == '\n')
		str++;
	return (str);
}

char		*ft_safe_extract(t_shell *shell,\
			char *str, char **tmp, int (*f)(char *, int))
{
	int		i;
	int		quote;

	i = 0;
	quote = 0;
	str = get_str(shell, str);
	while (str && str[i] > 0 && f(&str[i], quote))
	{
		if (str[i] == quote && !ft_is_escape(&str[i]))
		{
			quote = 0;
			i++;
		}
		else
		{
			quote = (str[i] == '\'' || str[i] == '\"')\
					&& !ft_is_escape(&str[i]) ? str[i] : quote;
			i++;
		}
	}
	*tmp = ft_substr(str, 0, i);
	return (&str[i]);
}
