/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 19:58:03 by dboyer            #+#    #+#             */
/*   Updated: 2020/06/11 12:34:07 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"
# include <errno.h>
# include <string.h>
# include <stdio.h>

int cd(char *path)
{ 
    char pwd[1000];
    getcwd(pwd, 1000);
    printf("%s\n", pwd);
    if (chdir(path))
    {
        ft_putstr("cd error: "), 
        ft_putstr(strerror(errno));
        ft_putchar('\n');
        getcwd(pwd, 1000);
        printf("%s\n", pwd);
        return (1);
    }
    getcwd(pwd, 1000);
    printf("%s\n", pwd);
    return (0);
}

int main(int argc, char *argv[])
{
    if (argc == 2)
        return (cd(argv[1]));
    else if (argc > 2)
    {
        ft_putstr("cd: string not in pwd: ");
        ft_putstr(argv[1]);
        ft_putchar('\n');
        return (1);
    }
    return (cd("/home/dess"));
}
