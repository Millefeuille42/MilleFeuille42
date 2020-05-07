/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 18:30:22 by mlabouri          #+#    #+#             */
/*   Updated: 2020/05/07 12:19:23 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Minishell/minishell.h"
#include <stdio.h>

int main(void)
{
	t_command *parsed;
	int i = 0;

	parsed = line_parser("this is a test; lolol jete nique; lol");

	while (parsed[i].command)
	{
		printf("\nCommand: |%s|\nArgs: ", parsed[i].command);
		int i2 = 0;
		while (parsed[i].args[i2])
		{
			printf("::|%s|", parsed[i].args[i2]);
			i2++;
		}
		i++;
	}

	return 0;
}
