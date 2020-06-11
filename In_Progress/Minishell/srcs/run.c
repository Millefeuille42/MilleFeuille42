/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 16:18:02 by dboyer            #+#    #+#             */
/*   Updated: 2020/06/11 16:31:44 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

int run(t_shell *shell)
{
    char		*input;

    shell->show_prompt(shell);
    get_next_line(0, &input);
    if (!ft_str_isequal(input, "exit"))
    {
        ft_printf("La commande est: %s\n", input);
        free(input);
        return (run(shell));
    }
    free(input);
    return (0);
}
