/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 11:20:36 by dboyer            #+#    #+#             */
/*   Updated: 2020/06/10 11:44:03 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(void)
{
    char *prompt;
    char *input;

    prompt = ft_getcwd();
    ft_printf("%s >> ", prompt);
    get_next_line(0, &input);
    ft_printf("%s\n", input);
    free(prompt);
    free(input);
    pwd();
    return (0);
}
