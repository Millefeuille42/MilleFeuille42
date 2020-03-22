/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 16:54:14 by mlabouri          #+#    #+#             */
/*   Updated: 2020/03/17 09:58:23 by mlabouri         ###   ########          */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void clear(char **to_free)
{
	int i;

	i = 0;
	while (to_free && to_free[i])
	{
		free(to_free[i]);
		i++;
	}
}

static int count(const char *str, char key)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == key)
		{
			while (str[i] == key)
				i++;
			count++;
		}
		else
			i++;
	}
	return (count);
}

t_command *line_parser(char *line)
{
	char **commands;
	char **parsed;
	t_command *ret;
	int i[2];

	i[0] = 0;
	commands = ft_split(line, ';');
	ret = malloc(sizeof(t_command) * count(line, ';'));
	while (commands[i[0]])
	{
		parsed = ft_split(commands[i[0]], ' ');
		ret[i[0]].command = parsed[0];
		ret[i[0]].args = malloc(sizeof(char *) * array_len(parsed) - 1);
		i[1] = 1;
		while (parsed[i[1]])
		{
			ret[i[0]].args[i[1] - 1] = parsed[i[1]];
			i[1]++;
		}
		ret[i[0]].args[i[1] - 1] = NULL;
		i[0]++;
	}
	clear(commands);
	ret[i[0]].command = NULL;
	return (ret);
}