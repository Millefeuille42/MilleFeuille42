/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 11:20:36 by dboyer            #+#    #+#             */
/*   Updated: 2020/06/10 15:55:03 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int run(void)
{
    t_string	prompt;
    char		*input;

    prompt = ft_getcwd();
    ft_printf("%s $ ", prompt.content);
    get_next_line(0, &input);
    prompt.clear(&prompt);
    if (!ft_str_isequal(input, "exit"))
    {
        ft_printf("La commande est: %s\n", input);
        free(input);
        return (run());
    }
    free(input);
    return (0);
}

int main(void)
{
    run();
    return (0);
}
