/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_arg.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 10:09:24 by mlabouri          #+#    #+#             */
/*   Updated: 2020/09/30 10:09:24 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_ARG_H
# define SORT_ARG_H

# include "minishell.h"

char	is_escape(const char *str, int i);
int		skip_wp(char *input, int i);
int		skip_quote(const char *input, int i, char quote);
char	*clean_quotes(char *str);
char	*clean_backslash(char *str);
#endif
