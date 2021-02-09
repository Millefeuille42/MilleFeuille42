/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 15:59:26 by dboyer            #+#    #+#             */
/*   Updated: 2020/09/29 11:43:12 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_find_command(char *path, char *cmd)
{
	DIR				*directory;
	struct dirent	*content;
	t_string		output;

	if (cmd && !ft_cinset('/', cmd))
	{
		if (ft_str_isequal(cmd, "exit"))
			return (ft_strdup("exit"));
		directory = opendir(path);
		while (directory && (content = readdir(directory)))
		{
			if (ft_str_isequal(content->d_name, cmd))
			{
				output = ft_string(path);
				output.push(&output, "/");
				output.push(&output, content->d_name);
				closedir(directory);
				return (output.content);
			}
		}
		if (directory)
			closedir(directory);
	}
	return (ft_cinset('/', cmd) ? cmd : NULL);
}
