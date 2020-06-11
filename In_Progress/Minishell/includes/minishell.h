/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 11:20:46 by dboyer            #+#    #+#             */
/*   Updated: 2020/06/10 15:10:28 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef MINISHELL_H
#   include "libft.h"
#   include "ft_list.h"
#	include "libft_string.h"

t_string	ft_getcwd(void);   /* Fonction qui retourne le chemin courant*/

void		pwd(void);          /* Fonction qui affiche le chemin courant avec un \n <- identique au vrai pwd */

#	define MINISHELL_H
#	endif
