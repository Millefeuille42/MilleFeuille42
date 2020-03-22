/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 16:55:21 by mlabouri          #+#    #+#             */
/*   Updated: 2020/03/16 17:02:53 by mlabouri         ###   ########          */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <string.h>
# include <stdlib.h>

typedef struct	s_command
{
	char		*command;
	char		**args;
}				t_command;

char			**ft_split(char const *s, char c);
int	array_len(char **array);

t_command *line_parser(char *line);

# endif
