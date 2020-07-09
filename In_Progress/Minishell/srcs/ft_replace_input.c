/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 09:15:20 by dboyer            #+#    #+#             */
/*   Updated: 2020/06/23 17:00:29 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


static  char *get_key(char *input)
{
    int i;

    i = 0;
    while (input[i])
    {
        if (!ft_isalpha(input[i]))
            return (ft_substr(input, 0, i));
        i++;
    }
    return (ft_strdup(input));

}

static  char *add_char(char *str, int c)
{
    size_t len;
    int i;
    char *ret;

    if (str && *str)
    {
        len = ft_strlen(str);
        if (!(ret = (char *)malloc(sizeof(char) * (len + 2))))
            return (NULL);
        i = 0;
        while (str[i])
        {
            ret[i] = str[i];
            i++;
        }
        ret[i] = c;
        ret[i + 1] = '\0';
    }
    else
    {
        if (!(ret = (char *)malloc(sizeof(char) * 2)))
            return (NULL);
        ret[0] = c;
        ret[1] = '\0';
    }
    return (ret);
}


char    *ft_replace_input(t_shell *shell, char *input)
{
	char *ret;
    char *key;
    char *new_ret;
    int i;

    i = 0;
	ret = NULL;
    while (input[i])
    {
        if (input[i] == '$' && (key = get_key(&input[i + 1])) && ft_strlen(key))
        {
            if (!ret)
            {
                ret = ft_substr(input, 0, i);
                new_ret = ft_strjoin(ret, shell->env_get(shell, key));
            }
            else
                new_ret = ft_strjoin(ret, shell->env_get(shell, key));
            input = &input[i] + ft_strlen(key) + 1;
            free(key);
            i = 0;
        }
        else
            new_ret = add_char(ret, input[i++]);
        if (ret)
            free(ret);
        ret = new_ret;
    }
    return (ret);
}
